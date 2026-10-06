#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int time;
    long long total_score;
} Record;


typedef struct {
    Record* data;
    size_t len;
    size_t cap;
} RecordVec


typedef struct {
    RecordVec* score_list;
    long long total_score; 
} ExamTracker;

RecordVec* init_record_vec();
bool push_into_vec(RecordVec* vec, int time, long long scores);
long long bin_search_floor();

ExamTracker* examTrackerCreate() {
   ExamTracker* obj = (ExamTracker*) malloc(sizeof(ExamTracker));
    obj->score_list = init_record_vec();
    obj->total_score = 0;
}

void examTrackerRecord(ExamTracker* obj, int time, int score) {
   obj->total_score += score;
    push_into_vec(obj->score_list, time, obj->total_score);
}

long long examTrackerTotalScore(ExamTracker* obj, int startTime, int endTime) {
   long long total_score = bin_search_floor(obj->score_list, endTime);
    long long lowest_score = bin_search_floor(obj->score_list, startTime - 1);

    return total_score - lowest_score;
}

void examTrackerFree(ExamTracker* obj) {
    
}


RecordVec* init_record_vec() {
    RecordVec* rec_vec = (*RecordVec) malloc(sizeof(RecordVec));
    rec_vec->data = NULL;
    rec_vec->len = 0;
    rec_vec->cap = 0;

    return rec_vec;
}

bool push_into_vec(RecordVec* vec, int time, long long scores) {
    
    if (vec->len == vec->cap) {
        size_t new_cap = vec->data ? vec->cap * 2 : 8;
        Record* new_data = realloc(vec->data, new_cap * sizeof(Record));

        if (new_data == NULL) {
            return false;
        }

        vec->data = new_data;
        vec->cap = new_cap;

    }

    Record curr_record = vec->data[vec->len];
    curr_record.time = time;
    curr_record.total_score = scores;

    vec->len++;
}


long long bin_search_floor(RecordVec* scores, int time) {
    
    int left = 0;
    int right = scores->len - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        Record curr = scores->data[mid];
        int curr_time = curr.time;
        
        if (time == curr_time) {
            return curr->total_score;
        }

        if (time < curr_time) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }

    return right >= 0 ? scores[right].total_score : 0;
}


/**
 * Your ExamTracker struct will be instantiated and called as such:
 * ExamTracker* obj = examTrackerCreate();
 * examTrackerRecord(obj, time, score);
 
 * long long param_2 = examTrackerTotalScore(obj, startTime, endTime);
 
 * examTrackerFree(obj);
*/
