rem ###########################
rem  N.Kozak // Lviv'2025
rem ############################

setlocal
@echo off 
SET PATH=tools;tools\TDM-GCC-32\bin;%PATH%
@echo off
set CR=0x0D
<nul set /p="Compile compiler:                                              [ in progress, please wait ]"
g++                                                                                                     ^
cw_sp2__2025_2026\cw.cpp                                                                                ^
cw_sp2__2025_2026\src\implementation\cli\cli.cpp                                                        ^
cw_sp2__2025_2026\src\implementation\generator\add.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\generator\and.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\generator\bitwise_and.cpp                                          ^
cw_sp2__2025_2026\src\implementation\generator\bitwise_not.cpp                                          ^
cw_sp2__2025_2026\src\implementation\generator\bitwise_or.cpp                                           ^
cw_sp2__2025_2026\src\implementation\generator\block.cpp                                                ^
cw_sp2__2025_2026\src\implementation\generator\div.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\generator\else_block.cpp                                           ^
cw_sp2__2025_2026\src\implementation\generator\else_if_then_block.cpp                                   ^
cw_sp2__2025_2026\src\implementation\generator\equal.cpp                                                ^
cw_sp2__2025_2026\src\implementation\generator\for_nonblockandblock.cpp                                 ^
cw_sp2__2025_2026\src\implementation\generator\generator.cpp                                            ^
cw_sp2__2025_2026\src\implementation\generator\goto_label.cpp                                           ^
cw_sp2__2025_2026\src\implementation\generator\greater.cpp                                              ^
cw_sp2__2025_2026\src\implementation\generator\greater_or_equal.cpp                                     ^
cw_sp2__2025_2026\src\implementation\generator\if_then_block.cpp                                        ^
cw_sp2__2025_2026\src\implementation\generator\index.cpp                                                ^
cw_sp2__2025_2026\src\implementation\generator\index_to_value.cpp                                       ^
cw_sp2__2025_2026\src\implementation\generator\input.cpp                                                ^
cw_sp2__2025_2026\src\implementation\generator\less.cpp                                                 ^
cw_sp2__2025_2026\src\implementation\generator\less_or_equal.cpp                                        ^
cw_sp2__2025_2026\src\implementation\generator\lrbind.cpp                                               ^
cw_sp2__2025_2026\src\implementation\generator\machinecodegen_addon.cpp                                 ^
cw_sp2__2025_2026\src\implementation\generator\machinecodegen_pattern.cpp                               ^
cw_sp2__2025_2026\src\implementation\generator\mod.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\generator\mul.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\generator\not.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\generator\not_equal.cpp                                            ^
cw_sp2__2025_2026\src\implementation\generator\null_statement.cpp                                       ^
cw_sp2__2025_2026\src\implementation\generator\objectcodegen_pattern.cpp                                ^
cw_sp2__2025_2026\src\implementation\generator\operand.cpp                                              ^
cw_sp2__2025_2026\src\implementation\generator\or.cpp                                                   ^
cw_sp2__2025_2026\src\implementation\generator\output.cpp                                               ^
cw_sp2__2025_2026\src\implementation\generator\repeat_until.cpp                                         ^
cw_sp2__2025_2026\src\implementation\generator\rlbind.cpp                                               ^
cw_sp2__2025_2026\src\implementation\generator\semicolon.cpp                                            ^
cw_sp2__2025_2026\src\implementation\generator\sub.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\generator\while_block.cpp                                          ^
cw_sp2__2025_2026\src\implementation\lexica\lexica.cpp                                                  ^
cw_sp2__2025_2026\src\implementation\preparer\preparer.cpp                                              ^
cw_sp2__2025_2026\src\implementation\semantics\semantics.cpp                                            ^
cw_sp2__2025_2026\src\implementation\syntax\syntax.cpp                                                  ^
-w                                                                                                      ^
-o                                                                                                      ^
cw_sp2__2025_2026\cw.exe                                                                                ^
-static-libgcc                                                                                          ^
-static-libstdc++                                                                                       ^
-std=c++11                                                                         
carriage_return.exe
<nul set /p="Compile compiler:                                              [  done, press any key ...  ]"
endlocal
pause 1 > nul
@echo on