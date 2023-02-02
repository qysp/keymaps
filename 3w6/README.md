# 3w6 (rev2) with Pimoroni trackball

This keyboard was bought second-hand from the creator [weteor](https://github.com/weteor).

## Compiling & flashing

1. `ln -s $HOME/repos/keymaps/3w6 $HOME/repos/qmk_firmware/keyboards/3w6/rev2/keymaps/qysp`
2. `qmk compile -kb 3w6/rev2 -km qysp`
3. `qmk flash -kb 3w6/rev2 -km qysp`
