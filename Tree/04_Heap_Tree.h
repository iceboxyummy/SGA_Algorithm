#pragma once

// 04_Heap_Tree.h

#pragma once

// けけけけけけけけけけけけ

// 04_Heap_Tree.h
/*
   『酔識授是泥
      い 覗鍵斗, 獣皇傾戚芝 獣什奴, 革闘趨滴 闘傾波 薦嬢, 錘慎端薦税 拙穣 什追糟元拭 紫遂
      い 酔識授是 泥澗 壕伸, 尻衣軒什闘, 琵生稽 姥薄亜管
      い 琵闘軒澗 酔識授是泥研 是背 幻級嬢像

   『 琵 闘軒(Heap Tree)
      い 刃穿 戚遭闘軒税 析曽, 捉惟 琵戚虞壱亀 採献陥.
      い 酔識授是 泥研 是馬食 幻級嬢遭 切戟姥繕
      い 食君鯵税 葵級 掻拭辞 置企葵戚暗蟹 置社葵聖 匙牽惟 達焼鎧亀系 幻級嬢遭 切戟姥繕.
      い 採乞葛球税 徹葵戚 切縦葛球左陥 牌雌滴陥(拙陥) -> 神硯託授 鎧顕託授税 託戚.
      い 笛 葵戚 雌是 傾婚拭 赤壱, 拙精 葵戚 馬是 傾婚拭 赤陥.
      い 掻差徹葵聖 買遂敗

   『 琵税 曽嫌

   1. 置企琵(max heap)
      い 採乞 葛球税 徹葵戚 切縦 葛球税 徹葵 左陥 滴暗蟹 旭精 刃穿 戚遭闘軒

   2. 置社琵(min heap)
      い 採乞 葛球税 徹葵戚 切縦 葛球税 徹葵 左陥 拙暗蟹 旭精 刃穿 戚遭闘軒


   『 琵拭辞税 採乞 葛球人 切縦 葛球税 淫域
      い 域至畷馬惟 馬奄是背辞 昔畿什研 1腰採斗 獣拙敗. 0生稽 馬澗 井酔亀 赤製
      い 薄仙 葛球税 昔畿什研 current虞壱 梅聖凶
         - 採乞 葛球税 昔畿什 : current / 2
         - 切縦 Left税 昔畿什 : current * 2
         - 切縦 Right税 昔畿什 : current * 2 + 1

   『 琵税 諮脊 肢薦
      い 琵税 諮脊
         - 琵拭 歯稽錘 推社亜 級嬢神檎 歯稽錘 葛球研 琵税 原走厳 是帖拭 諮脊廃陥.
         - 歯稽錘 葛球研 採乞 葛球級引 嘘発背亜檎辞 琵税 失霜 幻膳獣轍陥.

      い 琵税 肢薦
         - 欠闘税 葵聖 鋼発聖 馬壱, 欠闘人 原走厳葛球研 什尋廃陥.
         - 陥獣 葵聖 搾嘘背 亜檎辞 舛慶聖 廃陥.
*/

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

#include<Windows.h>
#define MAX_ARRAY_SIZE 256

class MaxHeap
{
public:
    MaxHeap()
    {
        ZeroMemory(values, sizeof(int) * MAX_ARRAY_SIZE);
    }

    void Push(int data) {}

    int Pop() {}

private:
    int values[MAX_ARRAY_SIZE];
    int heap_count = 0;
};

class MinHeap
{
public:
    MinHeap()
    {
        ZeroMemory(values, sizeof(int) * MAX_ARRAY_SIZE);
    }

    void Push(int data)
    {

    }

    int Pop()
    {}

private:
    int values[MAX_ARRAY_SIZE];
    int heap_count = 0;
};