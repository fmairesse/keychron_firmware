# Needed for making the keyboard return to run-time mode after flashing
DFU_ARGS = -d 0483:DF11 -a 0 -s 0x08000000:leave -R
# Enable combo for boot combo
COMBO_ENABLE = yes
