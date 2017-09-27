TypeMechTrix
===

An orthogonal handwired mechanical keyboard inspired by the Typematrix. Its layout is available [here](http://www.keyboard-layout-editor.com/#/gists/4110a75ecdb349b13e17). Its aim was to use Emacs easily, so that a Ctrl key is accessible with the right thumb while the spacebar is on the left thumb.

Hardware Supported: Teensy 2

Two connections with the teensy are available...

To get the firmware for this keyboard:
     make handwired-typemechtrix
To compile and copy the firmware to the teensy (requires [teensy-loader-cli](https://github.com/PaulStoffregen/teensy_loader_cli) installed and set in the PATH):
     make handwired-typemechtrix-teensy


See [build environment setup](https://docs.qmk.fm/build_environment_setup.html) then the [make instructions](https://docs.qmk.fm/make_instructions.html) for more information.
