INSTALL_DIR="/usr/bin/identitygen_"

# create install directory
create_install_dir() {
	sudo mkdir $INSTALL_DIR
}

cp_executable() {
	sudo cp ./build/identitygen $INSTALL_DIR 
}

cp_data() {
	sudo cp -R ./data $INSTALL_DIR
}

cp_icon() {
	sudo cp ./imgs/icon.png $INSTALL_DIR
}

create_shortcuts() {
	local SHORTCUT_DIR="/home/"$(whoami)"/.local/share/applications"
	local SHORTCUT_PATH=$SHORTCUT_DIR/identitygen.desktop
	local DESKTOP="/home/"$(whoami)"/Desktop"
	rm $SHORTCUT_PATH 2> /dev/null
	touch $SHORTCUT_PATH
	sudo chmod a+rx $SHORTCUT_PATH
	echo "[Desktop Entry]" >> $SHORTCUT_PATH
	echo "Version=1.0" >> $SHORTCUT_PATH
	echo "Type=Application" >> $SHORTCUT_PATH
	echo "Name=identitygen" >> $SHORTCUT_PATH
	echo "Icon="$INSTALL_DIR"/icon.png" >> $SHORTCUT_PATH
	echo "Exec="$INSTALL_DIR"/identitygen" >> $SHORTCUT_PATH
	echo "Terminal=False" >> $SHORTCUT_PATH
	cp $SHORTCUT_PATH $DESKTOP
}

create_install_dir
cp_executable
cp_data
cp_icon
create_shortcuts
echo "Installation completed. installed in /usr/bin/identitygen_"
