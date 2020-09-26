/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "../include/dicttrie.h"

#include "../include/pinyinime.h"

using namespace ime_pinyin;

/**
 * Build binary dictionary model. Make sure that ___BUILD_MODEL___ is defined
 * in dictdef.h.
 */
int main(int argc, char* argv[]) {
  DictTrie* dict_trie = new DictTrie();
  bool success;
 if (argc >= 3)
    success = dict_trie->build_dict(argv[1], argv[2]);
 else
    success = dict_trie->build_dict("../data/rawdict_utf16_65105_freq.txt",
                                    "../data/valid_utf16.txt");

 if (success) {
   printf("Build dictionary successfully.\n");
 } else {
   printf("Build dictionary unsuccessfully.\n");
   return -1;
 }

 if (argc >= 4)
  success = dict_trie->save_dict(argv[3]);
 else
  success = dict_trie->save_dict("dict_pinyin.dat");

 if (success) {
   printf("Save dictionary successfully.\n");
 } else {
   printf("Save dictionary unsuccessfully.\n");
   return -1;
 }

  // const char* userDict = "/home/davies/.config/fcitx/googlepinyin/userdict_pinyin.dat";
  // const char* syspath = "/a/project/sogou_pinyin_dict/dict_pinyin.dat";
  // bool result = ime_pinyin::im_open_decoder(syspath, userDict);
  // if (result) {
  //   printf("Operation im_open_decoder successfully.\n");
  // } else {
  //   printf("Operation im_open_decoder unsuccessfully.\n");
  // }
  // FILE * fd = NULL;
  // if (argc >= 4)
  //   fd = fopen("argv[3]", "wb");
  // else
  //   fd = fopen("dict_pinyin.dat", "wb");
  // fwrite("Hello world!", 1, 12, fd);
  // fclose(fd);

  return 0;
}
