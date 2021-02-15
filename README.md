### alipay-bt

This is a library which enables BipOS app developers to read and write arbitrary Bluetooth data from and to the Amazfit Bip.

__Note__: Requires the firmware to [be patched beforehand](https://github.com/neonsea/bip-fw-patch). You should also specify the correct offsets for your firmware in the library.

Due to the hardcoded offsets, apps using this library can target only a specific FW version, and aren't universal. To-do: fix this.
