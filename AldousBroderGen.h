#include "generator.h"

class AldousBroderGen : public Generator{
	
	public:AldousBroderGen(unsigned int height,unsigned int width, int seed);
	public:AldousBroderGen(unsigned int height,unsigned int width);
		bool generate();
		
		
};
