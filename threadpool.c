// defination
 
// 实现一个统一的队列的操作, 实现插入和删除功能 
#define insert(item, list) do { 
	if (list == NULL) { 	
		list->next = item;	
		item->next = NULL;
		item->pre = NULL;
	}
	else {
		item->next = list;
		list->pre = item;
		list = item;
	} 
} while (0);
 
#define remove(item, list) do {
	
} while (0);
 
/*
首先定义任务，tast = 任务回调函数 + 费用
在这里，task queue = task节点双向队列
*/ 
struct Task {
	void (*func)(void* arg);
	void* user_data;
	
	struct Task* prev;
	struct Task* next; 
};

/*
worker = 线程id + 线程状态
worker queue = worker点双向队列 
*/
struct Worker {
	pthread_t thread_id; 
	int terminate; 
	
	struct Worker* prev;
	struct Worker* next;
}; 

/*
manager/线程池 = 任务队列 + 工作队列 + 同步组件 
*/
struct Manager {
	struct Task* tasks;
	
	struct Worker* workers;
	
	pthread_mutex_t mutex;
	pthread_cond_t cond; 
};
typedef struct Manager ThreadPool; 


// interface

static void* threadCallBack(void* arg) {
	
}

/*
创建线程池,
创建一个含num个线程的线程池 
*/ 
int createThreadPool(ThreadPool* pool, int num) {
	if (pool == NULL) return -1;
	if (num <= 0) num = 1;
	memset(pool, 0, sizeof(ThreadPool));
	
	// init cond
	pthread_cond_t my_cond = PTHREAD_COND_INITIALIZER;
	memcpy(pool->cond, my_cond, sizeof(pthread_cond_t));
	// init mutex
	pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
	memcpy(pool->mutex, my_mutex, sizeof(pthread_mutex_t))
	// init worker
	for (int i = 0; i < num; i++) {
		Worker* worker = (worker*)malloc(sizeof(Worker));
		if (worker == NULL) {
			perror("malloc");
			return -1;
		} 
		memset(worker, 0, sizeof(Worker));
		pthread_create(&worker->thread_id, NULL, threadCallBack, worker);
		insert(worker, pool->workers);
	}
}

/*
销毁线程池 
*/
int destroyThreadPool() {
	
}
/*
给线程池加入任务
给pool加入task 
*/
int pushTask(ThreadPool* pool, Task* task) {
	
}




// debug
#if 1 
int main() {
	ThreadPool pool;
	createThreadPool(&pool, 20);
}

#endif 
