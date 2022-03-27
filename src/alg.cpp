// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int m = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        m += 1;
    }
  }
  return m;
}
int countPairs2(int *arr, int len, int value) {
  int m = 0;
  int t;
  for (int i = len - 1; i >= 0; i--) {
    if (arr[i] > value) {
      continue;
    } else {
      t = i;
      break;
    }
  }
  for (int i = 0; i < t - 1; i++) {
    for (int j = t; j >= i + 1; j--) {
      if (arr[i] + arr[j] == value)
        m++;
    }
  }
  return m;
}
int countPairs3(int *arr, int len, int value) {
  int m = 0, lb = 0, rb = len - 1;
  while (lb < rb - 1) {
    int mid_1 = (lb + rb) / 2;
    if (arr[mid_1] <= value)
      lb = mid_1;
    else
      rb = mid_1;
  }
  len = rb - 1;
  for (int i = 0; i < len; i++) {
    lb = i + 1, rb = len - 1;
    int q = 0;
    while (lb < rb) {
      int mid_2 = (lb + rb) / 2;
      if (arr[mid_2] < (value - arr[i]))
        lb = mid_2 + 1;
      else
        rb = mid_2;
    }
    while (arr[lb] == (value - arr[i])) {
      q++;
      lb++;
    }
    m += q;
  }
  return m;
}
