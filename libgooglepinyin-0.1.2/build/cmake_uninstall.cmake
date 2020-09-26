if (NOT EXISTS "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: \"/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/install_manifest.txt\"")
endif(NOT EXISTS "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/install_manifest.txt")

file(READ "/a/project/sogou_pinyin_dict/libgooglepinyin-0.1.2/build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")
foreach (file ${files})
    message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
    if (EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
        execute_process(
            COMMAND /usr/bin/cmake -E remove "$ENV{DESTDIR}${file}"
            OUTPUT_VARIABLE rm_out
            RESULT_VARIABLE rm_retval
        )
        if(NOT ${rm_retval} EQUAL 0)
            message(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
        endif (NOT ${rm_retval} EQUAL 0)
    else (EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
        message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
    endif (EXISTS "$ENV{DESTDIR}${file}" OR IS_SYMLINK "$ENV{DESTDIR}${file}")
endforeach(file)
