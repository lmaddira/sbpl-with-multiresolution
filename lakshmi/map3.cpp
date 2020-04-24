
#include <iostream>
#include <string.h>
#include <stdio.h>

int main(){
    FILE *fp = fopen("aisle_1m.cfg","wb");
    float discrete = 0.025; // discrete by 25 cm 
    // map length and width  2 x 1.6 m ==== 80 x 64
    // CAR parking space perpendicular 0.6 x 0.3 m  ==== 24 x 12 
    // clear car moving aisle space  1 m ==== 40 
    int wid = (int)(1.6/discrete)+1;
    int parking_wid = (int)(0.3/discrete)+1;
    int map_wid  = wid+(int)(0.1/discrete)+1;// 48+4;
    int map_length = (int)(2.0/discrete)+1; //10/discrete
    int aisle = (int)(1/discrete)+1 ;//2.5/discrete;
    std::cout<<" no of cells wid "<<wid<<"map_wid"<<map_wid<<" map_len  "<<map_length<<" aisle "<<aisle<<std::endl; 
    int map [map_length][map_wid];

    int obst = 254;

    fprintf(fp,"discretization(cells): %d %d \n",map_length, map_wid);
    fprintf(fp, "obsthresh: 254\n");
    fprintf(fp, "cost_inscribed_thresh: 253\n");
    fprintf(fp, "cost_possibly_circumscribed_thresh: 128 \n");
    fprintf(fp, "cellsize(meters): 0.025\n");
    fprintf(fp, "nominalvel(mpersecs): 1.0 \n");
    fprintf(fp, "timetoturn45degsinplace(secs): 20.0 \n");
    fprintf(fp, "start(meters,rads): 0.3 0.2 0 \n");
    fprintf(fp, "end(meters,rads): 1.2 0.85 1.57 \n");
    fprintf(fp, "environment:\n");


    for(int i=0 ; i<map_wid ; i++){

        for(int j=0;j< map_length ;j++){
            if(i<aisle ){
                map[i][j] = 0;
            }else if (i > wid ){
                map[i][j] = obst;
            }else if(j < (int)(map_length/2) || j > (int)((map_length/2) + (parking_wid)) ){
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
   // car width and length is 5 x 2 m scaling down to 2.5 m x 1 m  ===== 25 x 10