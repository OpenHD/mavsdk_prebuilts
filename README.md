# mavsdk_prebuilts

To build QOpenHD for android (and for mac, windows I think) we need the MAVSDK pre-builts
(e.g. mavsdk built into a static lib for the given platform).

While git might not be the ideal platform to upload libraries, this is the quickes / easiest solution I could come up with.

E.g. one can manually upload the required MAVSDK lib files into here.

Since QOpenHD development is generally done on linux (where we don't need this quirk) it is fine to not automate it - one just
needs to remember to upload the right artifacts into here from time to time ;)

NOTE: This is included as a git submodule in QOpenHD
