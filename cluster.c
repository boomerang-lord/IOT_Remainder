#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <map>
#include <time.h>

using namespace std;

static vector<int> 	doseTime;
static map<int, int> clusters;
static int 	dist = 60;
static int 	occ_th = 5;

void cluster( void )
{
	vector<int>::iterator itr;
	for(itr = doseTime.begin(); itr != doseTime.end(); ++itr){
		//printf("%d \n", (int)*itr);
	}
	printf("\n");
	
	map<int, int>::iterator mp_itr;
	for(itr = doseTime.begin(); itr != doseTime.end(); ++itr){
		int key = (*itr);
		key = key/dist;

		if( clusters.find(key)->first == key){
			int occurance = clusters.find(key)->second;
	//		printf("key = %d  occurance = %d\n", key, occurance);
			occurance++;
			clusters.erase(key);

			clusters.insert(pair<int, int >(key, occurance));


		}else{

			clusters.insert(pair<int, int >(key, 1));
		}	
	}

	map<int, int>::iterator mp;

	int start_time  = 0;
	int end_time	= 0;
	int flagTh      = 0;
	int current_time = 0;
	int occurance    = 0;

	//printf("%s	%s\n", "event time", "occurance");
	for(mp = clusters.begin(); mp != clusters.end(); ++mp){
		//printf("%d	%d\n", mp->first * 60, mp->second);
		if(mp->second >= occ_th){
			occurance	+= mp->second;
			if(start_time == 0){
				current_time	= mp->first;	// save the timestamp
				start_time	=  current_time;
				occurance	= mp->second;
			}else{
				if((current_time + 1) == mp->first) {// checking if consecutive
					current_time	= mp->first;	// save the timestamp

				}else{
					end_time 	= current_time;
					float dose_time	= (start_time + (( end_time - start_time )/2.0)) * dist/60;
					printf("1. start time = %d   end time = %d dose time = %f total occurance = %d\n",
						       	start_time *60, end_time *60, dose_time * 60, occurance);
					start_time	= 0;
					end_time 	= 0;
					occurance	= 0;
				}
			}

		}else{
			if(start_time != 0){
					end_time 	= current_time;
					float dose_time	= (start_time + (( end_time - start_time )/2.0)) * dist/60;
					printf("1. start time = %d   end time = %d dose time = %f total occurance = %d\n",
						       	start_time *60, end_time*60, dose_time * 60, occurance);
					//printf("2. start time = %d   end time = %d\n", start_time, end_time);

			}
			start_time	= 0;
			end_time 	= 0;
			occurance	= 0;


		}
	}
	if(start_time != 0){
					end_time 	= current_time;
					float dose_time	= (start_time + (( end_time - start_time )/2.0)) * dist/60;
					printf("1. start time = %d   end time = %d dose time = %f total occurance = %d\n", start_time *60,
						       	end_time *60, dose_time*60, occurance);
					//printf("2. start time = %d   end time = %d\n", start_time, end_time);

	}

}

int main(void)
{
	//int k = 1320 - 420;
	//
	//How to compile
	//g++ cluster.c
	
	int k = 300;
	int r = 0;
	int n = 50;
	int lower_cluster_start = 420;
	int upper_cluster_start = 900;
	srand(time(0));

	
	printf("\n\n-------CLUSTERING OF EVENT------------\n");
	printf("\n-------SUMULATION PARAMETERS------------\n");
	printf("Cluster distance ( end time - start time) = %d\n", dist);
        printf("Occurance threshold to cluster		  = %d\n", occ_th);
	printf("-----------------------------------------\n\n");	

	printf("We creates random values in two big buckets\n\n");
	printf("Bucket 1:\n");
	printf("	start time (minutes) = %d\n", lower_cluster_start);
	printf("	end time   (minutes) = %d\n\n", lower_cluster_start + k);
	
	printf("Bucket 2:\n");
	printf("	start time (minutes) = %d\n", upper_cluster_start);
	printf("	end time   (minutes) = %d\n\n", upper_cluster_start + k);
	
	for(int i = 0; i < n; i ++){
		r = rand();
		//  r % k gives value random value less than k
		r = (r % k) + lower_cluster_start; 
		doseTime.push_back(r);
		//printf(" random number below %d = %d\n",  k, rand() % k);
		printf("Time (Minutes) = %d\n", r);
	}

	k = 300;

	for(int i = 0; i < n; i ++){
		r = rand();
		//  r % k gives value random value less than k
		r = (r % k) + upper_cluster_start; 
		doseTime.push_back(r);
		//printf(" random number below %d = %d\n",  k, rand() % k);
		printf("Time (Minutes) = %d\n", r);
	}

	cluster();

	return 0;
}
