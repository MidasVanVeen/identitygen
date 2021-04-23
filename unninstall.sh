INSTALL_DIR="/usr/bin/identitygen_"
SHORTCUT_DIR="/home/"$(whoami)"/.local/share/applications"
SHORTCUT_PATH=$SHORTCUT_DIR/identitygen.desktop
SHORTCUT_DESKTOP="/home/"$(whoami)"/Desktop/identitygen.desktop"

unninstall() {
	sudo rm -r $INSTALL_DIR 2> /dev/null
	rm $SHORTCUT_PATH 2> /dev/null
	rm $SHORTCUT_DESKTOP 2> /dev/null
}

unninstall
echo "Unninstalled successfully"