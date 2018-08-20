/*srzy*/
#include <stdio.h>
char g[205][205];
int min(int a,int b){
  return a>b?b:a;
}
int main(){
	int T;scanf("%d",&T);
	while (T--){
		int w,h;scanf("%d%d",&w,&h);
		if (w%2==1&&h%2==1){
			for (int i=1;i<=w;i++){
				for (int j=1;j<=h;j++)printf("(");
			printf("\n");
			}
		}
		else if (w%2==0&&h%2==1){
			for (int i=1;i<=w;i++){
				for (int j=1;j<=h;j++){
					if (i%2)printf("(");
					else printf(")");
				}
				printf("\n");
			}
		}
		else if (w%2==1&&h%2==0){
			for (int i=1;i<=w;i++){
				for (int j=1;j<=h;j++){
					if (j<=h/2)printf("(");
					else printf(")");
				}
				printf("\n");
			}
		}
		else {
		  if (min(w,h)>=6){
			  if (w>=h){
				  for (int i=1;i<=w;i++){
					  for (int j=1;j<=h;j++){
					    if (i==1){
					      printf("(");
					    }
					    else if (i==w){
					      printf(")");
					    }
						  else if (i%2){
							  if (j==1)printf("(");
							  else if (j==h)printf(")");
							  else printf("%c",(j%2)?')':'(');
						  }
						  else {
							  printf("%c",(j%2)?'(':')');
						  }
					  }
					  printf("\n");
				  }
			  }
			  else {
				  for (int j=1;j<=h;j++){
					  for (int i=1;i<=w;i++){
					    if (j==1){
					      g[i][j]='(';
					    }
					    else if (j==h){
					      g[i][j]=')';
					    }
						  else if (j%2){
							  if (i==1)g[i][j]='(';
							  else if (i==w)g[i][j]=')';
							  else g[i][j]=(i%2)?')':'(';
						  }
						  else {
							  g[i][j]=(i%2)?'(':')';
						  }
					  }
				  }
				  for (int i=1;i<=w;i++){
					  for (int j=1;j<=h;j++)printf("%c",g[i][j]);
					  printf("\n");
				  }
			  }
			}
			else {
			  if (w>=h){
				  for (int i=1;i<=w;i++){
					  for (int j=1;j<=h;j++){
						  if (i%2){
							  if (j==1)printf("(");
							  else if (j==h)printf(")");
							  else printf("%c",(j%2)?')':'(');
						  }
						  else {
							  printf("%c",(j%2)?'(':')');
						  }
					  }
					  printf("\n");
				  }
			  }
			  else {
				  for (int j=1;j<=h;j++){
					  for (int i=1;i<=w;i++){
						  if (j%2){
							  if (i==1)g[i][j]='(';
							  else if (i==w)g[i][j]=')';
							  else g[i][j]=(i%2)?')':'(';
						  }
						  else {
							  g[i][j]=(i%2)?'(':')';
						  }
					  }
				  }
				  for (int i=1;i<=w;i++){
					  for (int j=1;j<=h;j++)printf("%c",g[i][j]);
					  printf("\n");
				  }
			  }
			}
		}
	}
}
