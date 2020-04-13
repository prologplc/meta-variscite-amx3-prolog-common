require conf/machine/include/var-ti33x.inc

# Use built-in LCD by default
XSERVER += "xf86-input-tslib"
MACHINE_GUI_CLASS = "smallscreen"
MACHINE_FEATURES += "touchscreen"

IMAGE_FSTYPES += "ubi tar.gz"

SERIAL_CONSOLE = "115200;ttyS0"

# ignore arago psplash changes
BBMASK = "meta-arago/meta-arago-distro/recipes-core/psplash"

# UBI information.  Note that this is board and kernel specific.  Changes
# in your kernel port may require changes in these variables.  For more
# details about this board please see
# http://processors.wiki.ti.com/index.php/UBIFS_Support

# do ubiattach /dev/ubi_ctrl -m 7 -O 2048
# From dmesg:
# UBI: smallest flash I/O unit:    2048
# UBI: logical eraseblock size:    126976 bytes
# from ubiattach stdout:
# UBI device number 0, total 1988 LEBs
MKUBIFS_ARGS = "-F -m 2048 -e 126976 -c 4600"

# do ubiattach /dev/ubi_ctrl -m 7 -O 2048
# from dmesg:
# UBI: smallest flash I/O unit:    2048
# UBI: physical eraseblock size:   131072 bytes (128 KiB)
# UBI: sub-page size:              512
# UBI: VID header offset:          2048 (aligned 2048)
UBINIZE_ARGS = "-m 2048 -p 128KiB -s 512 -O 2048"

DISTRO_FEATURES_append = " bluez5"

IMAGE_INSTALL_append = " \
        kernel-modules \
        wlconf \
        iw \
        wpa-supplicant-wl18xx \
        crda \
        ti-wifi-utils \
        wl18xx-firmware \
        bluez5 \
        bluez5-obex \
        bluez5-noinst-tools \
        bt-firmware \
        bash \
        fio \
        mtd-utils \
        i2c-tools \
        usbutils \
        alsa-utils \
        pciutils \
        devmem2 \
        memtester \
        udev-extraconf \
        iperf \
        iperf3 \
"