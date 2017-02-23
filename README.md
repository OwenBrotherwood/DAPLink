# WIP Support GCC

DAPLink doesn't seem to be GCC friendly.

As the present DAPLink is used for micro:bit, it would be nice for GCC.

<https://github.com/mbedmicro/DAPLink/tree/freescale>

## Support GCC

<https://github.com/mbedmicro/DAPLink/issues/197#issuecomment-281826833>

## UNKNOWN as to if the merged trees can be compiled with GCC

- <https://github.com/OwenBrotherwood/DAPLink/tree/freescale>
- <https://github.com/OwenBrotherwood/DAPLink/tree/CMSIS-DAP_IDAP-Link>

### Comments to merged work

The merge of the two trees into the <https://github.com/OwenBrotherwood/DAPLink/tree/freescale-i-sys> tree/branch/whatever gave:

```bash
C:\source\repos\github\OwenBrotherwood\DAPLink>git merge CMSIS-DAP_IDAP-Link
Auto-merging source/common/hal/nxp/lpc11u35/DAP_config.h
CONFLICT (modify/delete): interface/mdk/lpc11u35/lpc11u35_interface.uvproj deleted in HEAD and
modified in CMSIS-DAP_IDAP-Link. Version CMSIS-DAP_IDAP-Link of interface/mdk/lpc11u35/lpc11u35
_interface.uvproj left in tree.
Automatic merge failed; fix conflicts and then commit the result.
error: addinfo_cache failed for path 'source/common/hal/nxp/lpc11u35/DAP_config.h'

C:\source\repos\github\OwenBrotherwood\DAPLink>git mergetool

This message is displayed because 'merge.tool' is not configured.
See 'git mergetool --tool-help' or 'git help config' for more details.
'git mergetool' will now attempt to use one of the following tools:
tortoisemerge emerge vimdiff
Merging:
interface/mdk/lpc11u35/lpc11u35_interface.uvproj

Deleted merge conflict for 'interface/mdk/lpc11u35/lpc11u35_interface.uvproj':
  {local}: deleted
  {remote}: modified file
Use (m)odified or (d)eleted file, or (a)bort? m
```

# DAPLink

## Setup
Skip any step where a compatible tool already exists

1. Install [Python 2.7.x](https://www.python.org/downloads/) and make sure it's added to path
2. Install [pip](https://pip.pypa.io/en/latest/installing.html) and make sure <python_install_loc>\Scripts it's added to path
3. Install DAPLink dependencies using pip (see command below)
4. Install [Keil MDK-ARM](https://www.keil.com/download/product/) 

```
daplink> pip install -r requirements.txt
```

## Develop
1. Generate project files. This should be done everytime you pull new changes
```
> pgen export -t uvision
```
For adding new targets start from template and use these docs...

## Contribute
Check out the issue tracker.

##ToDo
- Create a test
- Document how to use
- Document how to contribute
