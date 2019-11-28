#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *imagemOriginal, *imagemCifrada;
   unsigned char byte;
   int  contadorBytes=0;
   char marcaDAgua[4]="aed";

   imagemOriginal = fopen("imagemoriginal.jpg","rb");
   imagemCifrada = fopen("imagemcomwatermarking.jpg","wb");

   if(imagemOriginal == NULL || imagemCifrada == NULL)
   {
      printf("\nArquivo JPG nao pode ser aberto...");
      getchar();
      exit(1);
   }

   printf("Gerando copia da imagem com watermarking...\n");

   while (!feof(imagemOriginal))
   {
         if (!feof(imagemOriginal))
         {
             fread(&byte, sizeof(unsigned char), 1, imagemOriginal);
             contadorBytes++;
             fwrite(&byte, sizeof(unsigned char), 1, imagemCifrada);
             if (contadorBytes == 256)
                 fwrite(&marcaDAgua, sizeof(char),3,imagemCifrada);
         }
   }

   fclose(imagemOriginal);
   fclose(imagemCifrada);

   printf("Fim do processo de insercao de Watermarking...\n");
   getchar();

   return 0;
}
