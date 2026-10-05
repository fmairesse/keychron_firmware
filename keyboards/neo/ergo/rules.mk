# Needed for making the keyboard return to run-time mode after flashing
DFU_ARGS = -d 0483:DF11 -a 0 -s 0x08000000:leave -R
COMBO_ENABLE = yes
# KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = yes
SEND_STRING_ENABLE = yes
