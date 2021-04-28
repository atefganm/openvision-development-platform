SUMMARY = "rsync for cloud storage"
DESCRIPTION = "Rclone is a command line program to sync files and directories to and from different cloud storage providers \
    Alibaba Cloud (Aliyun) Object Storage System (OSS) Amazon Drive Amazon S3 Backblaze B2 Box Ceph DigitalOcean Spaces \
    Dreamhost Dropbox FTP Google Cloud Storage Google Drive HTTP Hubic Jottacloud IBM COS S3 Koofr Memset Memstore Mega \
    Microsoft Azure Blob Storage Microsoft OneDrive Minio Nextcloud OVH OpenDrive OpenStack Swift Oracle Cloud Storage \
    ownCloud pCloud put.io QingStor Rackspace Cloud Files Scaleway SFTP Wasabi WebDAV Yandex Disk The local filesystem"
HOMEPAGE = "https://rclone.org/"

GO_IMPORT = "github.com/rclone/rclone"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://src/${GO_IMPORT}/COPYING;md5=bed161b82a1ecab65ff7ba3c3b960439"

inherit go gitpkgv upx_compress

PV = "1.x+git${SRCPV}"
PKGV = "1.x+git${GITPKGV}"

S = "${WORKDIR}/git"

SRC_URI = "git://${GO_IMPORT}.git;protocol=https;destsuffix=git/src/${GO_IMPORT} \
    file://rclonefs"


do_install_append() {
    rm ${D}${bindir}/test*
    install -m 755 ${WORKDIR}/rclonefs ${D}${bindir}
    ln -s rclone ${D}${bindir}/mount.rclone
}
