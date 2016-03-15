#pragma once

#include "main.h"

class BatchUpdate{
public:
	BatchUpdate(int32_t batchSize_);
	~BatchUpdate();


	int32_t* getHostSrc(){return h_edgeSrc;}	
	int32_t* getHostDst(){return h_edgeDst;}	
	int32_t* getHostIndIncomplete(){return h_indIncomplete;}	
	int32_t getHostIndCount(){return h_indCount[0];}	
	int32_t getHostBatchSize(){return h_batchSize[0];}
	int32_t* getHostIndDuplicate(){return h_indDuplicate;}	
	int32_t getHostDuplicateCount(){return h_dupCount[0];}	
	int32_t* getHostDupRelPos(){return h_dupRelPos;}	

	
	__device__ int32_t* getDeviceSrc(){return d_edgeSrc;}	
	__device__ int32_t* getDeviceDst(){return d_edgeDst;}	
	__device__ int32_t* getDeviceIndIncomplete(){return d_indIncomplete;}	
	__device__ int32_t* getDeviceIndCount(){return d_indCount;}	
	__device__ int32_t* getDeviceIndDuplicate(){return d_indDuplicate;}	
	__device__ int32_t* getDeviceDuplicateCount(){return d_dupCount;}	
	__device__ int32_t* getDeviceDupRelPos(){return d_dupRelPos;}	


	__device__ int32_t getDeviceBatchSize(){return d_batchSize[0];}

	void resetHostIndCount(){h_indCount[0]=0;}
	void resetDeviceIndCount(){checkCudaErrors(cudaMemset(d_indCount,0,sizeof(int32_t)));}

	void resetHostDuplicateCount(){h_dupCount[0]=0;}
	void resetDeviceDuplicateCount(){checkCudaErrors(cudaMemset(d_dupCount,0,sizeof(int32_t)));}


	BatchUpdate* devicePtr(){return d_batchUpdate;}

	void copyHostToDevice();
	void copyDeviceToHost();
private:

	BatchUpdate* d_batchUpdate;

	int32_t *h_batchSize,*h_edgeSrc,*h_edgeDst, *h_indIncomplete, *h_indCount, *h_indDuplicate, *h_dupRelPos,*h_dupCount;
	int32_t *d_batchSize,*d_edgeSrc,*d_edgeDst, *d_indIncomplete, *d_indCount, *d_indDuplicate, *d_dupRelPos,*d_dupCount;

};

