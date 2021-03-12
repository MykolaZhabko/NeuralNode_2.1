for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < x; j++)
    {
      fwrite(&img_arr[i][j].blue, sizeof(img_arr[i][j].blue), 1, out);
      fwrite(&img_arr[i][j].green, sizeof(img_arr[i][j].green), 1, out);
      fwrite(&img_arr[i][j].red, sizeof(img_arr[i][j].red), 1, out);
    }
    for (int p = 0; p < padding_bit; p++)
    {
      fwrite(&padding_bit, 1, 1, out);
    }
  }