#!/bin/sh

brandcheck=`cat /etc/openvision/brand`
modelcheck=`cat /etc/openvision/model`

if [ $modelcheck == "tf7700" ]; then
	mknod -m 0660 /dev/rc c 62 1
else
	mknod -m 0660 /dev/rc c 147 1
fi

if [ $brandcheck == "edisionargus" ] || [ $brandcheck == "fulan" ] || [ $brandcheck == "forever" ] || [ $modelcheck == "hl101" ] || [ $modelcheck == "ufs912" ] || [ $modelcheck == "ufs913" ] || [ $modelcheck == "octagon1008" ] || [ $modelcheck == "opt9600" ]; then
	/bin/evremote2 10 120 &
elif [ $brandcheck == "atemio" ] || [ $brandcheck == "cuberevo" ] || [ $brandcheck == "hs" ] || [ $modelcheck == "atevio7500" ] || [ $modelcheck == "fortis_hdbox" ]; then
	/bin/evremote2 10 140 &
elif [ $modelcheck == "tf7700" ]; then
	/bin/evremote2 110 10 &
elif [ $modelcheck == "ufc960" ] || [ $modelcheck == "ufs922" ]; then
	/bin/evremote2 0 0 10 120 &
elif [ $modelcheck == "arivalink200" ]; then
	/bin/evremote2 useLircdName &
else
	/bin/evremote2 &
fi
