# Cantor (rev1)

This keyboard was the second self-built QMK keyboard.

## Compiling & flashing

1. `ln -s $HOME/repos/keymaps/cantor $HOME/repos/qmk_firmware/keyboards/cantor/keymaps/qysp`
2. `qmk compile -kb cantor -km qysp`
3. `qmk flash -kb cantor -km qysp`
