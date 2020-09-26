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
#include "../include/mystdlib.h"
#include "../include/searchutility.h"

namespace ime_pinyin {

bool is_system_lemma(LemmaIdType lma_id) {
  return (0 < lma_id && lma_id <= kSysDictIdEnd);
}

bool is_user_lemma(LemmaIdType lma_id) {
  return (kUserDictIdStart <= lma_id && lma_id <= kUserDictIdEnd);
}

bool is_composing_lemma(LemmaIdType lma_id) {
  return (kLemmaIdComposing == lma_id);
}

int cmp_lpi_with_psb(const void *p1, const void *p2) {
  if ((static_cast<const LmaPsbItem*>(p1))->psb >
      (static_cast<const LmaPsbItem*>(p2))->psb)
    return 1;
  if ((static_cast<const LmaPsbItem*>(p1))->psb <
      (static_cast<const LmaPsbItem*>(p2))->psb)
    return -1;
  return 0;
}

int cmp_lpi_with_unified_psb(const void *p1, const void *p2) {
  const LmaPsbItem *item1 = static_cast<const LmaPsbItem*>(p1);
  const LmaPsbItem *item2 = static_cast<const LmaPsbItem*>(p2);

  // The real unified psb is psb1 / lma_len1 and psb2 * lma_len2
  // But we use psb1 * lma_len2 and psb2 * lma_len1 to get better
  // precision.
  size_t up1 = item1->psb * (item2->lma_len);
  size_t up2 = item2->psb * (item1->lma_len);
  if (up1 < up2) {
    return -1;
  }
  if (up1 > up2) {
    return 1;
  }
  return 0;
}

int cmp_lpi_with_id(const void *p1, const void *p2) {
  if ((static_cast<const LmaPsbItem*>(p1))->id <
      (static_cast<const LmaPsbItem*>(p2))->id)
    return -1;
  if ((static_cast<const LmaPsbItem*>(p1))->id >
      (static_cast<const LmaPsbItem*>(p2))->id)
    return 1;
  return 0;
}

int cmp_lpi_with_hanzi(const void *p1, const void *p2) {
  if ((static_cast<const LmaPsbItem*>(p1))->hanzi <
      (static_cast<const LmaPsbItem*>(p2))->hanzi)
    return -1;
  if ((static_cast<const LmaPsbItem*>(p1))->hanzi >
      (static_cast<const LmaPsbItem*>(p2))->hanzi)
    return 1;

  return 0;
}

int cmp_lpsi_with_str(const void *p1, const void *p2) {
  return utf16_strcmp((static_cast<const LmaPsbStrItem*>(p1))->str,
                      (static_cast<const LmaPsbStrItem*>(p2))->str);
}


int cmp_hanzis_1(const void *p1, const void *p2) {
  if (*static_cast<const char16*>(p1) <
      *static_cast<const char16*>(p2))
    return -1;

  if (*static_cast<const char16*>(p1) >
      *static_cast<const char16*>(p2))
    return 1;
  return 0;
}

int cmp_hanzis_2(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 2);
}

int cmp_hanzis_3(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 3);
}

int cmp_hanzis_4(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 4);
}

int cmp_hanzis_5(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 5);
}

int cmp_hanzis_6(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 6);
}

int cmp_hanzis_7(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 7);
}

int cmp_hanzis_8(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 8);
}

int cmp_hanzis_9(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 9);
}

int cmp_hanzis_10(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 10);
}

int cmp_hanzis_11(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 11);
}

int cmp_hanzis_12(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 12);
}

int cmp_hanzis_13(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 13);
}

int cmp_hanzis_14(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 14);
}

int cmp_hanzis_15(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 15);
}

int cmp_hanzis_16(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 16);
}

int cmp_hanzis_17(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 17);
}

int cmp_hanzis_18(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 18);
}

int cmp_hanzis_19(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 19);
}

int cmp_hanzis_20(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 20);
}

int cmp_hanzis_21(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 21);
}

int cmp_hanzis_22(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 22);
}

int cmp_hanzis_23(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 23);
}

int cmp_hanzis_24(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 24);
}

int cmp_hanzis_25(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 25);
}

int cmp_hanzis_26(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 26);
}

int cmp_hanzis_27(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 27);
}

int cmp_hanzis_28(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 28);
}

int cmp_hanzis_29(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 29);
}

int cmp_hanzis_30(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 30);
}

int cmp_hanzis_31(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 31);
}

int cmp_hanzis_32(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 32);
}

int cmp_hanzis_33(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 33);
}

int cmp_hanzis_34(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 34);
}

int cmp_hanzis_35(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 35);
}

int cmp_hanzis_36(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 36);
}

int cmp_hanzis_37(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 37);
}

int cmp_hanzis_38(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 38);
}

int cmp_hanzis_39(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 39);
}

int cmp_hanzis_40(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 40);
}

int cmp_hanzis_41(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 41);
}

int cmp_hanzis_42(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 42);
}

int cmp_hanzis_43(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 43);
}

int cmp_hanzis_44(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 44);
}

int cmp_hanzis_45(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 45);
}

int cmp_hanzis_46(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 46);
}

int cmp_hanzis_47(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 47);
}

int cmp_hanzis_48(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 48);
}

int cmp_hanzis_49(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 49);
}

int cmp_hanzis_50(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 50);
}

int cmp_hanzis_51(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 51);
}

int cmp_hanzis_52(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 52);
}

int cmp_hanzis_53(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 53);
}

int cmp_hanzis_54(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 54);
}

int cmp_hanzis_55(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 55);
}

int cmp_hanzis_56(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 56);
}

int cmp_hanzis_57(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 57);
}

int cmp_hanzis_58(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 58);
}

int cmp_hanzis_59(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 59);
}

int cmp_hanzis_60(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 60);
}

int cmp_hanzis_61(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 61);
}

int cmp_hanzis_62(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 62);
}

int cmp_hanzis_63(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 63);
}

int cmp_hanzis_64(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 64);
}

int cmp_hanzis_65(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 65);
}

int cmp_hanzis_66(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 66);
}

int cmp_hanzis_67(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 67);
}

int cmp_hanzis_68(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 68);
}

int cmp_hanzis_69(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 69);
}

int cmp_hanzis_70(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 70);
}

int cmp_hanzis_71(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 71);
}

int cmp_hanzis_72(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 72);
}

int cmp_hanzis_73(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 73);
}

int cmp_hanzis_74(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 74);
}

int cmp_hanzis_75(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 75);
}

int cmp_hanzis_76(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 76);
}

int cmp_hanzis_77(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 77);
}

int cmp_hanzis_78(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 78);
}

int cmp_hanzis_79(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 79);
}

int cmp_hanzis_80(const void *p1, const void *p2) {
  return  utf16_strncmp(static_cast<const char16*>(p1),
                        static_cast<const char16*>(p2), 80);
}

int cmp_npre_by_score(const void *p1, const void *p2) {
  if ((static_cast<const NPredictItem*>(p1))->psb >
      (static_cast<const NPredictItem*>(p2))->psb)
    return 1;

  if ((static_cast<const NPredictItem*>(p1))->psb <
      (static_cast<const NPredictItem*>(p2))->psb)
    return -1;

  return 0;
}

int cmp_npre_by_hislen_score(const void *p1, const void *p2) {
  if ((static_cast<const NPredictItem*>(p1))->his_len <
      (static_cast<const NPredictItem*>(p2))->his_len)
    return 1;

  if ((static_cast<const NPredictItem*>(p1))->his_len >
      (static_cast<const NPredictItem*>(p2))->his_len)
    return -1;

  if ((static_cast<const NPredictItem*>(p1))->psb >
      (static_cast<const NPredictItem*>(p2))->psb)
    return 1;

  if ((static_cast<const NPredictItem*>(p1))->psb <
      (static_cast<const NPredictItem*>(p2))->psb)
    return -1;

  return 0;
}

int cmp_npre_by_hanzi_score(const void *p1, const void *p2) {
  int ret_v = (utf16_strncmp((static_cast<const NPredictItem*>(p1))->pre_hzs,
      (static_cast<const NPredictItem*>(p2))->pre_hzs, kMaxPredictSize));
  if (0 != ret_v)
    return ret_v;

  if ((static_cast<const NPredictItem*>(p1))->psb >
      (static_cast<const NPredictItem*>(p2))->psb)
    return 1;

  if ((static_cast<const NPredictItem*>(p1))->psb <
      (static_cast<const NPredictItem*>(p2))->psb)
    return -1;

  return 0;
}

size_t remove_duplicate_npre(NPredictItem *npre_items, size_t npre_num) {
  if (NULL == npre_items || 0 == npre_num)
    return 0;

  myqsort(npre_items, npre_num, sizeof(NPredictItem), cmp_npre_by_hanzi_score);

  size_t remain_num = 1;  // The first one is reserved.
  for (size_t pos = 1; pos < npre_num; pos++) {
    if (utf16_strncmp(npre_items[pos].pre_hzs,
                      npre_items[remain_num - 1].pre_hzs,
                      kMaxPredictSize) != 0) {
      if (remain_num != pos) {
        npre_items[remain_num] = npre_items[pos];
      }
      remain_num++;
    }
  }
  return remain_num;
}

size_t align_to_size_t(size_t size) {
  size_t s = sizeof(size_t);
  return (size + s -1) / s * s;
}

}  // namespace ime_pinyin
