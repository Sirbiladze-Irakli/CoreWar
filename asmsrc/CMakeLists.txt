cmake_minimum_required(VERSION 3.15)
project(asmsrc C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(asmsrc
        add_node.c
        add_token.c
        arg_reader.c
        asm.c
        fill_magic_header.c
        get_next_line.c
        parse.c
        read_and_write.c
        s_compiler.c
        take_tokens.c
        tools.c
        champ_code.c)
