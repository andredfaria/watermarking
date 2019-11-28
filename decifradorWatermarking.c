#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *imagemCifrada, *imagemDecifrada;
   unsigned char byte;
   int  contadorBytes=0;
   char marcaDAgua[4]="aed";

   imagemCifrada = fopen("imagemcomwatermarking.jpg","rb");
   imagemDecifrada = fopen("imagemdecifrada.jpg","wb");

   if(imagemCifrada == NULL || imagemDecifrada == NULL)
   {
      printf("\nArquivo JPG nao pode ser aberto...");
      getchar();
      exit(1);
   }

   printf("Recuperando a imagem original sem watermarking...\n");

   contadorBytes = 0;
   while (!feof(imagemCifrada))
   {
         if (!feof(imagemCifrada))
         {
             fread(&byte, sizeof(unsigned char), 1, imagemCifrada);
             contadorBytes++;
             if (contadorBytes > 256 && contadorBytes <= 259)
                 continue;
             fwrite(&byte, sizeof(unsigned char), 1, imagemDecifrada);
         }
   }

   fclose(imagemCifrada);
   fclose(imagemDecifrada);

   printf("Fim do processo de retirada da watermarking...\n");
   getchar();

   return 0;
}
