require recovery-web.inc

SRCREV = "5d68fcde19886c1fdf4987ec18ceaa346a40c68a"
SRCREV_dm520 = "40a427447ca0398a3511db10ea0919938b89a6c8"
SRCREV_dm820 = "${SRCREV_dm7080}"
SRCREV_dm900 = "046d365084e29c2dcacc0e9befd04f6947c6f7e3"
SRCREV_dm920 = "${SRCREV_dm900}"
SRCREV_dm7080 = "5fa8b020dde379faf3cec6142049f57c03fdb205"

inherit opendreambox-git

BRANCH = "master"
BRANCH_dm520 = "dm520"
BRANCH_dm820 = "${BRANCH_dm7080}"
BRANCH_dm900 = "dm900"
BRANCH_dm920 = "${BRANCH_dm900}"
BRANCH_dm7080 = "dm7080"

COMPATIBLE_MACHINE = "^(dm520|dm820|dm900|dm920|dm7080)$"