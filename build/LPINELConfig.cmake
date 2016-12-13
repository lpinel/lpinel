# Authors: Juan G Victores
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
# Evident yet unstandarized names

IF (NOT LPINEL_FOUND)

  SET(LPINEL_LIBRARIES "ExampleLibrary")
  SET(LPINEL_INCLUDE_DIRS "/home/teo/repos/lpinel/libraries/ExampleLibrary")
  SET(LPINEL_LINK_DIRS "/home/teo/repos/lpinel/build/lib")
  SET(LPINEL_DEFINES "")
  SET(LPINEL_MODULE_PATH "/home/teo/repos/lpinel/cmake")

  SET (LPINEL_FOUND TRUE)
ENDIF (NOT LPINEL_FOUND)
