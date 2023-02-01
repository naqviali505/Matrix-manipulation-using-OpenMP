#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
using namespace std;
int main()
{
    srand(time(NULL));
    double init_time;
	int a1[100][100] ,result[100][100];
	int size = 100;
    init_time=omp_get_wtime();
	cout<<"Execution Time at init_time for default scheduling: "<<init_time<<endl;

#pragma omp parallel for

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a1[i][j] = rand() % 50;

		}
	}
#pragma omp parallel for
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			for(int k=0;k<size;k++)
			{
				result[i][j] +=a1[i][k] * a1[k][j];

			}
		}

	}
    double final_time = omp_get_wtime();
	cout<<"\nTime final_time for default Scheduling: \n"<<final_time<<endl;
    cout<<"Difference in execution time: "<<final_time-init_time<<endl;
    init_time=omp_get_wtime();
	cout<<"Execution Time at init_time for dynamic scheduling: "<<init_time<<endl;
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a1[i][j] = rand() % 50;
		}
	}
#pragma omp parallel for schedule(dynamic)
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			for(int k=0;k<size;k++)
			{
				result[i][j] +=a1[i][k] * a1[k][j];

			}
		}

	}
	final_time = omp_get_wtime();
	cout<<"\nTime final_time for Dynamic Scheduling: \n"<<final_time<<endl;
    cout<<"Difference in execution time: "<<final_time-init_time<<endl;
    init_time=omp_get_wtime();
	cout<<"Execution Time at init_time for Static Scheduling: "<<init_time<<endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a1[i][j] = rand()%50;
		}
	}
#pragma omp parallel for schedule (static) num_threads(4)
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			for(int k=0;k<size;k++)
			{
				result[i][j] +=a1[i][k] * a1[k][j];
			}
		}
	}
	final_time = omp_get_wtime();
	cout<<"\nTime final_time for Static Scheduling: \n"<<final_time<<endl;
    cout<<"Difference in execution time: "<<final_time-init_time<<endl;
	return 0;
}