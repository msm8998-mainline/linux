#!/bin/bash
# SPDX-License-Identifier: GPL-2.0

### Customisable variables
export DEFCONFIG=msm8998_defconfig

export KBUILD_OUTPUT=out
export KBUILD_BUILD_USER="$USER"
export KBUILD_BUILD_HOST=$(cat /etc/hostname)
export DTB_IMAGE="qcom/msm8998-mtp.dtb" # Change it to your preferred device-tree.
export KERNEL_IMAGE="Image.gz"
export RAMDISK_PATH="../initramfs" # Change it to your preferred initramfs root path.
export RAMDISK_IMAGE="initramfs.cpio.gz"

# mkbootimg vars (Fill the values with the help of AIK)
export BOARD_PAGE_SIZE="4096"
export BOARD_KERNEL_BASE=""
export BOARD_KERNEL_OFFSET=""
export BOARD_RAMDISK_OFFSET=""
export BOARD_SECOND_OFFSET=""
export BOARD_TAGS_OFFSET=""
export BOARD_KERNEL_CMDLINE="clk_ignore_unused quiet loglevel=5 modprobe.blacklist=ipa"
export SIGN_BOOT_IMG=0 # 0 = false; 1 = true

### End

# Set up environment
function envsetup() {
    export ARCH=arm64
    export CROSS_COMPILE=aarch64-linux-gnu-
    export CROSS_COMPILE_ARM32=arm-none-eabi-
    export CROSS_COMPILE_COMPAT=arm-none-eabi-
}

# Wrapper to utilise all available cores
function m() {
    make -j$(nproc) ARCH="$ARCH" CROSS_COMPILE="$CROSS_COMPILE" "$@"
}

# Regenerate defconfig
function rd() {
    m "$DEFCONFIG" savedefconfig || return
    cp "$KBUILD_OUTPUT"/defconfig arch/"$ARCH"/configs/"$DEFCONFIG"
}

# Generate boot.img
function bootimg_gen() {
    local kernel_image_base="$KBUILD_OUTPUT/arch/$ARCH/boot/$KERNEL_IMAGE"
    local dtb_path="$KBUILD_OUTPUT/arch/$ARCH/boot/dts/$DTB_IMAGE"
    local kernel_image_dtb="$KBUILD_OUTPUT/arch/$ARCH/boot/${KERNEL_IMAGE}-dtb"
    local output_bootimg="$KBUILD_OUTPUT/boot.img"

    # Generate $KERNEL_IMAGE
    cat "$kernel_image_base" "$dtb_path" > "$kernel_image_dtb"

    # Generate $RAMDISK_IMAGE
    (cd "$RAMDISK_PATH" && find . \( -name ".git" -o -name "$RAMDISK_IMAGE" \) -prune -o -print | cpio -o -H newc | gzip > "$RAMDISK_IMAGE")

    mkbootimg \
        --kernel "$kernel_image_dtb" \
        --cmdline "$BOARD_KERNEL_CMDLINE" \
        --ramdisk "$RAMDISK_PATH/$RAMDISK_IMAGE" \
        --base "$BOARD_KERNEL_BASE" \
        --kernel_offset "$BOARD_KERNEL_OFFSET" \
        --ramdisk_offset "$BOARD_RAMDISK_OFFSET" \
        --second_offset "$BOARD_SECOND_OFFSET" \
        --tags_offset "$BOARD_TAGS_OFFSET" \
        --pagesize "$BOARD_PAGE_SIZE" \
        -o "$output_bootimg"

    if [ "$SIGN_BOOT_IMG" -eq 1 ]; then
        signer/boot_signer /boot $output_bootimg \
            signer/verity.pk8 signer/verity.x509.pem \
            $output_bootimg
    fi

    echo "Successfully created boot image: $output_bootimg"
}

# Build kernel
function mka() {
    rd || return
    m "$KERNEL_IMAGE" dtbs || return
    bootimg_gen || return
}

envsetup
