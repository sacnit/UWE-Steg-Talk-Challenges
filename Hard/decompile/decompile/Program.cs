﻿static void Main()
    {
      string[] strArray1 = new string[30]
      {
        "zrWoxvnzss",
        "DAQCUV1Zhx",
        "D4hABsEUAA",
        "GUN53AAUAV",
        "AAAAGUwSQB",
        "AAAAQIAAAA",
        "AABSLAAAQA",
        "wiAYqG5MLy",
        "AZ1vTOcd+t",
        "xkkWIcwSQJ",
        "oTQAAsAe1d",
        "TSalFh80OA",
        "mZAwBAEAAA",
        "AADgOBAAwA",
        "T7AAAAJAgC",
        "FaX7112ezA",
        "tEVMJpVWEy",
        "AECAAAQLRF",
        "GUN56ZQ1kf",
        "AAhAAAA0SU",
        "AAQCAoABDs",
        "oTQAAsAe1d",
        "VdWYsZGAAA",
        "AAAAAAAGAQ",
        "AAKBQAAEAA",
        "AADgOBAAwA",
        "JhjobxQepE",
        "TPZYyfhHP9",
        "AAAAAAweAA",
        "EU"
      };
      int[] numArray = new int[30]
      {
        18,
        24,
        12,
        5,
        2,
        9,
        7,
        19,
        16,
        14,
        22,
        27,
        25,
        21,
        11,
        20,
        10,
        26,
        23,
        13,
        28,
        4,
        6,
        8,
        1,
        3,
        15,
        17,
        0,
        29
      };
      string[] strArray2 = new string[strArray1.Length];
      for (int index = 0; index < numArray.Length; ++index)
        strArray2[numArray[index]] = strArray1[index];
      string str = new string(string.Join("", strArray2).Reverse<char>().ToArray<char>());
      Console.WriteLine(str);
    }
Main();