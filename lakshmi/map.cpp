
#include <iostream>
#include <string.h>
#include <stdio.h>

int main(){
    FILE *fp = fopen("test.cfg","wb");
    float discrete = 0.025; // discrete by 25 cm 
    // map length and width will be 20 m x  12 m - scaling down to 10 x 6 m ==== 400 x 220
    // CAR parking space perpendicular  would be 6 x 3 m scaled down to 3x1.5 m  ==== 120 x 60
    // clear car moving aisle space = 5 m  scale down to 2.5 m ==== 100 
    int map_wid  = 220+40;// 6/discrete;
    int map_length = 400; //10/discrete
    int aisle = 100 ;//2.5/discrete; 
    int map [map_length][map_wid];

    int obst = 254;

    fprintf(fp,"discretization(cells): 400 260 \n");
    fprintf(fp, "obsthresh: 254\n");
    fprintf(fp, "cost_inscribed_thresh: 253\n");
    fprintf(fp, "cost_possibly_circumscribed_thresh: 128 \n");
    fprintf(fp, "cellsize(meters): 0.025\n");
    fprintf(fp, "nominalvel(mpersecs): 1.0 \n");
    fprintf(fp, "timetoturn45degsinplace(secs): 20.0 \n");
    fprintf(fp, "start(meters,rads): 1.0 2.0 0 \n");
    fprintf(fp, "end(meters,rads): 5.5 4.0 1.57 \n");
    fprintf(fp, "environment:\n");


    for(int i=0 ; i<map_wid ; i++){

        for(int j=0;j< map_length ;j++){
            if(i<aisle ){
                map[i][j] = 0;
            }else if (i > aisle + 120 ){
                map[i][j] = obst;
            }else if(j < 200 || j > 260 ){
                map[i][j] = obst;
            }else{
                map[i][j] = 0;
            }
            fprintf (fp, "%d",map[i][j]);
            fprintf(fp," ");
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;

}
   // car width and length is 5 x 2 m scaling down to 2.5 m x 1 m  ===== 100 x 40