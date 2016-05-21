#pragma once

#include <Kore/Graphics4/Graphics.h>
#include <vulkan/vulkan.h>

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef RegisterClass
#undef RegisterClass
#endif

namespace Kore {
	namespace Graphics5 {
		struct Vertices {
			VkBuffer buf;
			VkDeviceMemory mem;
		};

		class VertexBuffer;

		class VertexBufferImpl {
		public:
			VertexBufferImpl(int count, int instanceDataStepRate);
			void unset();
			float* data;
			int myCount;
			int myStride;
			uint bufferId;
			//#if defined SYS_ANDROID || defined SYS_HTML5 || defined SYS_TIZEN
			Graphics4::VertexStructure structure;
			//#endif

			Vertices vertices;
			VkMemoryAllocateInfo mem_alloc;

			int instanceDataStepRate;
			int setVertexAttributes(int offset);
			int index;
		public:
			static VertexBuffer* current;
		};
	}
}
