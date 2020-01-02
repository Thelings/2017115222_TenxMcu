SET C51INC=G:\danpj\C51\Inc;G:\danpj\C51\Inc\tenx
SET C51LIB=G:\danpj\C51\Lib
SET CPU_TYPE=TM52F5268B
SET CPU_VENDOR=tenx
SET UV2_TARGET=Target 1
SET CPU_XTAL=0x007A1200
"G:\danpj\C51\BIN\A51.EXE" @".\Objects\STARTU~1._IA"
"G:\danpj\C51\BIN\C51.EXE" @".\Objects\display.__i"
"G:\danpj\C51\BIN\C51.EXE" @".\Objects\init.__i"
"G:\danpj\C51\BIN\C51.EXE" @".\Objects\main.__i"
"G:\danpj\C51\BIN\BL51.EXE" @".\Objects\FLASHI~1.LNP"
"G:\danpj\C51\BIN\OH51.EXE" ".\Objects\Flashing lights" 
