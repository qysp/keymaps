# 3w6 (rev2) with Pimoroni trackball

This keyboard was bought second-hand from the creator [weteor](https://github.com/weteor).

## Compiling & flashing

0. `export $QMK_CUSTOM_KEYMAPS=/path/to/dir`
1. `ln -s $QMK_CUSTOM_KEYMAPS/3w6 $QMK_HOME/keyboards/3w6/rev2/keymaps/qysp`
2. `qmk compile -kb 3w6/rev2 -km qysp`
3. `qmk flash -kb 3w6/rev2 -km qysp`
