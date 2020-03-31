/* FNA3D - 3D Graphics Library for FNA
 *
 * Copyright (c) 2020 Ethan Lee
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 * claim that you wrote the original software. If you use this software in a
 * product, an acknowledgment in the product documentation would be
 * appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and must not be
 * misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * Ethan "flibitijibibo" Lee <flibitijibibo@flibitijibibo.com>
 *
 */

#if FNA3D_DRIVER_VULKAN

#include "FNA3D_Driver.h"
#include "FNA3D_Driver_Vulkan.h"

#include <SDL.h>
#include <SDL_syswm.h>
#include <SDL_vulkan.h>

/* static vars */

static PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = NULL;

#define VULKAN_GLOBAL_FUNCTION(name) static PFN_##name name = NULL;
#include "FNA3D_Driver_Vulkan_global_funcs.h"
#undef VULKAN_GLOBAL_FUNCTION

/* Internal Structures */

typedef struct FNAVulkanRenderer
{
	FNA3D_Device *parentDevice;
	VkInstance instance;
	VkDevice logicalDevice;

	#define VULKAN_INSTANCE_FUNCTION(ext, ret, func, params) \
		vkfntype_##func func;
	#include "FNA3D_Driver_Vulkan_instance_funcs.h"
	#undef VULKAN_INSTANCE_FUNCTION

	#define VULKAN_DEVICE_FUNCTION(ext, ret, func, params) \
		vkfntype_##func func;
	#include "FNA3D_Driver_Vulkan_device_funcs.h"
	#undef VULKAN_DEVICE_FUNCTION
} FNAVulkanRenderer;

typedef struct QueueFamilyIndices {
	uint32_t graphicsFamily;
	uint32_t presentFamily;
} QueueFamilyIndices;

typedef struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	VkSurfaceFormatKHR *formats;
	uint32_t formatsLength;
	VkPresentModeKHR *presentModes;
	uint32_t presentModesLength;
} SwapChainSupportDetails;

/* translations arrays go here */

static const char* VkErrorMessages(VkResult code)
{
	const char *errorString;

	switch(code)
	{
		case VK_ERROR_OUT_OF_HOST_MEMORY:
			errorString = "Out of host memory";
			break;

		case VK_ERROR_OUT_OF_DEVICE_MEMORY:
			errorString = "Out of device memory";
			break;

		case VK_ERROR_INITIALIZATION_FAILED:
			errorString = "Initialization failed";
			break;

		case VK_ERROR_LAYER_NOT_PRESENT:
			errorString = "Layer not present";
			break;

		case VK_ERROR_EXTENSION_NOT_PRESENT:
			errorString = "Extension not present";
			break;

		case VK_ERROR_FEATURE_NOT_PRESENT:
			errorString = "Feature not present";
			break;

		case VK_ERROR_TOO_MANY_OBJECTS:
			errorString = "Too many objects";
			break;

		case VK_ERROR_DEVICE_LOST:
			errorString = "Device lost";
			break;

		case VK_ERROR_INCOMPATIBLE_DRIVER:
			errorString = "Incompatible driver";
			break;

		default:
			errorString = "Unknown";
			break;
	}

	return errorString;
}

/* Init/Quit */

uint8_t VULKAN_PrepareWindowAttributes(uint32_t *flags)
{
	/* TODO: INCOMPLETE */

	*flags = SDL_WINDOW_VULKAN;
	return 1;
}

void VULKAN_GetDrawableSize(void* window, int32_t *x, int32_t *y)
{
	SDL_Vulkan_GetDrawableSize((SDL_Window*) window, x, y);
}

void VULKAN_DestroyDevice(FNA3D_Device *device)
{
	/* TODO: INCOMPLETE */

	FNAVulkanRenderer *renderer = (FNAVulkanRenderer*) device->driverData;

	renderer->vkDestroyDevice(renderer->logicalDevice, NULL);

	SDL_free(renderer);
	SDL_free(device);
}

/* Begin/End Frame */

void VULKAN_BeginFrame(FNA3D_Renderer *driverData)
{
	/* TODO */
}

void VULKAN_SwapBuffers(
	FNA3D_Renderer *driverData,
	FNA3D_Rect *sourceRectangle,
	FNA3D_Rect *destinationRectangle,
	void* overrideWindowHandle
) {
	/* TODO */
}

void VULKAN_SetPresentationInterval(
	FNA3D_Renderer *driverData,
	FNA3D_PresentInterval presentInterval
) {
	/* TODO */
}

/* Drawing */

void VULKAN_Clear(
	FNA3D_Renderer *driverData,
	FNA3D_ClearOptions options,
	FNA3D_Vec4 *color,
	float depth,
	int32_t stencil
) {
	/* TODO */
}

void VULKAN_DrawIndexedPrimitives(
	FNA3D_Renderer *driverData,
	FNA3D_PrimitiveType primitiveType,
	int32_t baseVertex,
	int32_t minVertexIndex,
	int32_t numVertices,
	int32_t startIndex,
	int32_t primitiveCount,
	FNA3D_Buffer *indices,
	FNA3D_IndexElementSize indexElementSize
) {
	/* TODO */
}

void VULKAN_DrawInstancedPrimitives(
	FNA3D_Renderer *driverData,
	FNA3D_PrimitiveType primitiveType,
	int32_t baseVertex,
	int32_t minVertexIndex,
	int32_t numVertices,
	int32_t startIndex,
	int32_t primitiveCount,
	int32_t instanceCount,
	FNA3D_Buffer *indices,
	FNA3D_IndexElementSize indexElementSize
) {
	/* TODO */
}

void VULKAN_DrawPrimitives(
	FNA3D_Renderer *driverData,
	FNA3D_PrimitiveType primitiveType,
	int32_t vertexStart,
	int32_t primitiveCount
) {
	/* TODO */
}

FNA3DAPI void VULKAN_DrawUserIndexedPrimitives(
	FNA3D_Renderer *driverData,
	FNA3D_PrimitiveType primitiveType,
	void* vertexData,
	int32_t vertexOffset,
	int32_t numVertices,
	void* indexData,
	int32_t indexOffset,
	FNA3D_IndexElementSize indexElementSize,
	int32_t primitiveCount
) {
	/* TODO */
}

FNA3DAPI void VULKAN_DrawUserPrimitives(
	FNA3D_Renderer *driverData,
	FNA3D_PrimitiveType primitiveType,
	void* vertexData,
	int32_t vertexOffset,
	int32_t primitiveCount
) {
	/* TODO */
}

/* Mutable Render States */

void VULKAN_SetViewport(FNA3D_Renderer *driverData, FNA3D_Viewport *viewport)
{
	/* TODO */
}

void VULKAN_SetScissorRect(FNA3D_Renderer *driverData, FNA3D_Rect *scissor)
{
	/* TODO */
}

void VULKAN_GetBlendFactor(
	FNA3D_Renderer *driverData,
	FNA3D_Color *blendFactor
) {
	/* TODO */
}

void VULKAN_SetBlendFactor(
	FNA3D_Renderer *driverData,
	FNA3D_Color *blendFactor
) {
	/* TODO */
}

int32_t VULKAN_GetMultiSampleMask(FNA3D_Renderer *driverData)
{
	/* TODO */
}

void VULKAN_SetMultiSampleMask(FNA3D_Renderer *driverData, int32_t mask)
{
	/* TODO */
}

int32_t VULKAN_GetReferenceStencil(FNA3D_Renderer *driverData)
{
	/* TODO */
}

void VULKAN_SetReferenceStencil(FNA3D_Renderer *driverData, int32_t ref)
{
	/* TODO */
}

/* Immutable Render States */

void VULKAN_SetBlendState(
	FNA3D_Renderer *driverData,
	FNA3D_BlendState *blendState
) {
	/* TODO */
}

void VULKAN_SetDepthStencilState(
	FNA3D_Renderer *driverData,
	FNA3D_DepthStencilState *depthStencilState
) {
	/* TODO */
}

void VULKAN_ApplyRasterizerState(
	FNA3D_Renderer *driverData,
	FNA3D_RasterizerState *rasterizerState
) {
	/* TODO */
}

void VULKAN_VerifySampler(
	FNA3D_Renderer *driverData,
	int32_t index,
	FNA3D_Texture *texture,
	FNA3D_SamplerState *sampler
) {
	/* TODO */
}

/* Vertex State */

void VULKAN_ApplyVertexBufferBindings(
	FNA3D_Renderer *driverData,
	FNA3D_VertexBufferBinding *bindings,
	int32_t numBindings,
	uint8_t bindingsUpdated,
	int32_t baseVertex
) {
	/* TODO */
}

void VULKAN_ApplyVertexDeclaration(
	FNA3D_Renderer *driverData,
	FNA3D_VertexDeclaration *vertexDeclaration,
	void* ptr,
	int32_t vertexOffset
) {
	/* TODO */
}

/* Render Targets */

void VULKAN_SetRenderTargets(
	FNA3D_Renderer *driverData,
	FNA3D_RenderTargetBinding *renderTargets,
	int32_t numRenderTargets,
	FNA3D_Renderbuffer *renderbuffer,
	FNA3D_DepthFormat depthFormat
) {
	/* TODO */
}

void VULKAN_ResolveTarget(
	FNA3D_Renderer *driverData,
	FNA3D_RenderTargetBinding *target
) {
	/* TODO */
}

/* Backbuffer Functions */

void VULKAN_ResetBackbuffer(
	FNA3D_Renderer *driverData,
	FNA3D_PresentationParameters *presentationParameters
) {
	/* TODO */
}

void VULKAN_ReadBackbuffer(
	FNA3D_Renderer *driverData,
	void* data,
	int32_t dataLen,
	int32_t startIndex,
	int32_t elementCount,
	int32_t elementSizeInBytes,
	int32_t x,
	int32_t y,
	int32_t w,
	int32_t h
) {
	/* TODO */
}

void VULKAN_GetBackbufferSize(
	FNA3D_Renderer *driverData,
	int32_t *w,
	int32_t *h
) {
	/* TODO */
}

FNA3D_SurfaceFormat VULKAN_GetBackbufferSurfaceFormat(
	FNA3D_Renderer *driverData
) {
	/* TODO */
}

FNA3D_DepthFormat VULKAN_GetBackbufferDepthFormat(FNA3D_Renderer *driverData)
{
	/* TODO */
}

int32_t VULKAN_GetBackbufferMultiSampleCount(FNA3D_Renderer *driverData)
{
	/* TODO */
}

/* Textures */

FNA3D_Texture* VULKAN_CreateTexture2D(
	FNA3D_Renderer *driverData,
	FNA3D_SurfaceFormat format,
	int32_t width,
	int32_t height,
	int32_t levelCount,
	uint8_t isRenderTarget
) {
	/* TODO */
}

FNA3D_Texture* VULKAN_CreateTexture3D(
	FNA3D_Renderer *driverData,
	FNA3D_SurfaceFormat format,
	int32_t width,
	int32_t height,
	int32_t depth,
	int32_t levelCount
) {
	/* TODO */
}

FNA3D_Texture* VULKAN_CreateTextureCube(
	FNA3D_Renderer *driverData,
	FNA3D_SurfaceFormat format,
	int32_t size,
	int32_t levelCount,
	uint8_t isRenderTarget
) {
	/* TODO */
}

void VULKAN_AddDisposeTexture(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *texture
) {
	/* TODO */
}

void VULKAN_SetTextureData2D(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *texture,
	FNA3D_SurfaceFormat format,
	int32_t x,
	int32_t y,
	int32_t w,
	int32_t h,
	int32_t level,
	void* data,
	int32_t dataLength
) {
	/* TODO */
}

void VULKAN_SetTextureData3D(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *texture,
	FNA3D_SurfaceFormat format,
	int32_t level,
	int32_t left,
	int32_t top,
	int32_t right,
	int32_t bottom,
	int32_t front,
	int32_t back,
	void* data,
	int32_t dataLength
) {
	/* TODO */
}

void VULKAN_SetTextureDataCube(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *texture,
	FNA3D_SurfaceFormat format,
	int32_t x,
	int32_t y,
	int32_t w,
	int32_t h,
	FNA3D_CubeMapFace cubeMapFace,
	int32_t level,
	void* data,
	int32_t dataLength
) {
	/* TODO */
}

void VULKAN_SetTextureDataYUV(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *y,
	FNA3D_Texture *u,
	FNA3D_Texture *v,
	int32_t w,
	int32_t h,
	void* ptr
) {
	/* TODO */
}

void VULKAN_GetTextureData2D(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *texture,
	FNA3D_SurfaceFormat format,
	int32_t textureWidth,
	int32_t textureHeight,
	int32_t level,
	int32_t x,
	int32_t y,
	int32_t w,
	int32_t h,
	void* data,
	int32_t startIndex,
	int32_t elementCount,
	int32_t elementSizeInBytes
) {
	/* TODO */
}

void VULKAN_GetTextureData3D(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *texture,
	FNA3D_SurfaceFormat format,
	int32_t left,
	int32_t top,
	int32_t front,
	int32_t right,
	int32_t bottom,
	int32_t back,
	int32_t level,
	void* data,
	int32_t startIndex,
	int32_t elementCount,
	int32_t elementSizeInBytes
) {
	/* TODO */
}

void VULKAN_GetTextureDataCube(
	FNA3D_Renderer *driverData,
	FNA3D_Texture *texture,
	FNA3D_SurfaceFormat format,
	int32_t textureSize,
	FNA3D_CubeMapFace cubeMapFace,
	int32_t level,
	int32_t x,
	int32_t y,
	int32_t w,
	int32_t h,
	void* data,
	int32_t startIndex,
	int32_t elementCount,
	int32_t elementSizeInBytes
) {
	/* TODO */
}

/* Renderbuffers */

FNA3D_Renderbuffer* VULKAN_GenColorRenderbuffer(
	FNA3D_Renderer *driverData,
	int32_t width,
	int32_t height,
	FNA3D_SurfaceFormat format,
	int32_t multiSampleCount,
	FNA3D_Texture *texture
) {
	/* TODO */
}

FNA3D_Renderbuffer* VULKAN_GenDepthStencilRenderbuffer(
	FNA3D_Renderer *driverData,
	int32_t width,
	int32_t height,
	FNA3D_DepthFormat format,
	int32_t multiSampleCount
) {
	/* TODO */
}

void VULKAN_AddDisposeRenderbuffer(
	FNA3D_Renderer *driverData,
	FNA3D_Renderbuffer *renderbuffer
) {
	/* TODO */
}

/* Vertex Buffers */

FNA3D_Buffer* VULKAN_GenVertexBuffer(
	FNA3D_Renderer *driverData,
	uint8_t dynamic,
	FNA3D_BufferUsage usage,
	int32_t vertexCount,
	int32_t vertexStride
) {
	/* TODO */
}
void VULKAN_AddDisposeVertexBuffer(
	FNA3D_Renderer *driverData,
	FNA3D_Buffer *buffer
) {
	/* TODO */
}

void VULKAN_SetVertexBufferData(
	FNA3D_Renderer *driverData,
	FNA3D_Buffer *buffer,
	int32_t offsetInBytes,
	void* data,
	int32_t dataLength,
	FNA3D_SetDataOptions options
) {
	/* TODO */
}

void VULKAN_GetVertexBufferData(
	FNA3D_Renderer *driverData,
	FNA3D_Buffer *buffer,
	int32_t offsetInBytes,
	void* data,
	int32_t startIndex,
	int32_t elementCount,
	int32_t elementSizeInBytes,
	int32_t vertexStride
) {
	/* TODO */
}

/* Index Buffers */

FNA3D_Buffer* VULKAN_GenIndexBuffer(
	FNA3D_Renderer *driverData,
	uint8_t dynamic,
	FNA3D_BufferUsage usage,
	int32_t indexCount,
	FNA3D_IndexElementSize indexElementSize
) {
	/* TODO */
}

FNA3DAPI void VULKAN_AddDisposeIndexBuffer(
	FNA3D_Renderer *driverData,
	FNA3D_Buffer *buffer
) {
	/* TODO */
}

void VULKAN_SetIndexBufferData(
	FNA3D_Renderer *driverData,
	FNA3D_Buffer *buffer,
	int32_t offsetInBytes,
	void* data,
	int32_t dataLength,
	FNA3D_SetDataOptions options
) {
	/* TODO */
}

void VULKAN_GetIndexBufferData(
	FNA3D_Renderer *driverData,
	FNA3D_Buffer *buffer,
	int32_t offsetInBytes,
	void* data,
	int32_t startIndex,
	int32_t elementCount,
	int32_t elementSizeInBytes
) {
	/* TODO */
}

/* Effects */

typedef struct MOJOSHADER_effect MOJOSHADER_effect;
typedef struct MOJOSHADER_effectTechnique MOJOSHADER_effectTechnique;
typedef struct MOJOSHADER_effectStateChanges MOJOSHADER_effectStateChanges;

FNA3D_Effect* VULKAN_CreateEffect(
	FNA3D_Renderer *driverData,
	uint8_t *effectCode,
	uint32_t effectCodeLength
) {
	/* TODO */
}

FNA3D_Effect* VULKAN_CloneEffect(
	FNA3D_Renderer *driverData,
	FNA3D_Effect *effect
) {
	/* TODO */
}

void VULKAN_AddDisposeEffect(
	FNA3D_Renderer *driverData,
	FNA3D_Effect *effect
) {
	/* TODO */
}

void VULKAN_ApplyEffect(
	FNA3D_Renderer *driverData,
	FNA3D_Effect *effect,
	MOJOSHADER_effectTechnique *technique,
	uint32_t pass,
	MOJOSHADER_effectStateChanges *stateChanges
) {
	/* TODO */
}

void VULKAN_BeginPassRestore(
	FNA3D_Renderer *driverData,
	FNA3D_Effect *effect,
	MOJOSHADER_effectStateChanges *stateChanges
) {
	/* TODO */
}

void VULKAN_EndPassRestore(
	FNA3D_Renderer *driverData,
	FNA3D_Effect *effect
) {
	/* TODO */
}

/* Queries */

FNA3D_Query* VULKAN_CreateQuery(FNA3D_Renderer *driverData)
{
	/* TODO */
}

void VULKAN_AddDisposeQuery(FNA3D_Renderer *driverData, FNA3D_Query *query)
{
	/* TODO */
}

void VULKAN_QueryBegin(FNA3D_Renderer *driverData, FNA3D_Query *query)
{
	/* TODO */
}

void VULKAN_QueryEnd(FNA3D_Renderer *driverData, FNA3D_Query *query)
{
	/* TODO */
}

uint8_t VULKAN_QueryComplete(FNA3D_Renderer *driverData, FNA3D_Query *query)
{
	/* TODO */
}

int32_t VULKAN_QueryPixelCount(
	FNA3D_Renderer *driverData,
	FNA3D_Query *query
) {
	/* TODO */
}

/* Feature Queries */

uint8_t VULKAN_SupportsDXT1(FNA3D_Renderer *driverData)
{
	/* TODO */
}

uint8_t VULKAN_SupportsS3TC(FNA3D_Renderer *driverData)
{
	/* TODO */
}

uint8_t VULKAN_SupportsHardwareInstancing(FNA3D_Renderer *driverData)
{
	/* TODO */
}

uint8_t VULKAN_SupportsNoOverwrite(FNA3D_Renderer *driverData)
{
	/* TODO */
}

int32_t VULKAN_GetMaxTextureSlots(FNA3D_Renderer *driverData)
{
	/* TODO */
}

int32_t VULKAN_GetMaxMultiSampleCount(FNA3D_Renderer *driverData)
{
	/* TODO */
}

/* Debugging */

FNA3DAPI void VULKAN_SetStringMarker(FNA3D_Renderer *driverData, const char *text)
{
	/* TODO */
}

/* Buffer Objects */

intptr_t VULKAN_GetBufferSize(FNA3D_Buffer *buffer)
{
	/* TODO */
}

/* Effect Objects */

MOJOSHADER_effect* VULKAN_GetEffectData(FNA3D_Effect *effect)
{
	/* TODO */
}

static uint8_t LoadGlobalFunctions(void)
{
    vkGetInstanceProcAddr = SDL_Vulkan_GetVkGetInstanceProcAddr();
    if(!vkGetInstanceProcAddr)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "SDL_Vulkan_GetVkGetInstanceProcAddr(): %s\n",
                     SDL_GetError());

        return 0;
    }

	#define VULKAN_GLOBAL_FUNCTION(name)                                               		\
		name = (PFN_##name)vkGetInstanceProcAddr(VK_NULL_HANDLE, #name);                  	\
		if(!name)                                                                         	\
		{                                                                                 	\
			SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,                                    	\
						"vkGetInstanceProcAddr(VK_NULL_HANDLE, \"" #name "\") failed\n");	\
			return 0;                                                             		   	\
		}

	#include "FNA3D_Driver_Vulkan_global_funcs.h"
	#undef VULKAN_GLOBAL_FUNCTION

	return 1;
}

static void LoadInstanceFunctions(
	FNAVulkanRenderer *renderer
) {
	#define VULKAN_INSTANCE_FUNCTION(ext, ret, func, params) \
		renderer->func = (vkfntype_##func) vkGetInstanceProcAddr(renderer->instance, #func);
	#include "FNA3D_Driver_Vulkan_instance_funcs.h"
	#undef VULKAN_INSTANCE_FUNCTION
}

static void LoadDeviceFunctions(
	FNAVulkanRenderer *renderer
) {
	#define VULKAN_DEVICE_FUNCTION(ext, ret, func, params) \
		renderer->func = (vkfntype_##func) renderer->vkGetDeviceProcAddr(renderer->logicalDevice, #func);
	#include "FNA3D_Driver_Vulkan_device_funcs.h"
	#undef VULKAN_DEVICE_FUNCTION
}

static uint8_t CheckInstanceExtensionSupport(
	const char** requiredExtensions,
	uint32_t requiredExtensionsLength
) {
	uint32_t extensionCount;
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

	VkExtensionProperties availableExtensions[extensionCount];
	vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, availableExtensions);

	for (uint32_t i = 0; i < requiredExtensionsLength; i++)
	{
		uint8_t extensionFound = 0;

		for (uint32_t j = 0; j < extensionCount; j++)
		{
			if (SDL_strcmp(requiredExtensions[i], availableExtensions[j].extensionName) == 0)
			{
				extensionFound = 1;
				break;
			}
		}

		if (!extensionFound)
		{
			return 0;
		}
	}

	return 1;
}

static uint8_t CheckDeviceExtensionSupport(
	FNAVulkanRenderer *renderer,
	VkPhysicalDevice physicalDevice,
	const char** requiredExtensions,
	uint32_t requiredExtensionsLength
) {
	uint32_t extensionCount;
	renderer->vkEnumerateDeviceExtensionProperties(physicalDevice, NULL, &extensionCount, NULL);

	VkExtensionProperties availableExtensions[extensionCount];
	renderer->vkEnumerateDeviceExtensionProperties(physicalDevice, NULL, &extensionCount, availableExtensions);

	for (uint32_t i = 0; i < requiredExtensionsLength; i++)
	{
		uint8_t extensionFound = 0;

		for (uint32_t j = 0; j < extensionCount; j++)
		{
			if (SDL_strcmp(requiredExtensions[i], availableExtensions[j].extensionName) == 0)
			{
				extensionFound = 1;
				break;
			}
		}

		if (!extensionFound)
		{
			return 0;
		}
	}

	return 1;
}

static SwapChainSupportDetails QuerySwapChainSupport(
	FNAVulkanRenderer *renderer,
	VkPhysicalDevice physicalDevice,
	VkSurfaceKHR surface
)
{
	SwapChainSupportDetails details;
	VkResult result;

	result = renderer->vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, &details.capabilities);
	if (result != VK_SUCCESS)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"vkGetPhysicalDeviceSurfaceCapabilitiesKHR: %s\n",
			VkErrorMessages(result)
		);

		details.formatsLength = 0;
		details.presentModesLength = 0;
		return details;
	}

	uint32_t formatCount;
	renderer->vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, NULL);

	if (formatCount != 0)
	{
		details.formats = SDL_malloc(sizeof(VkSurfaceFormatKHR) * formatCount);
		details.formatsLength = formatCount;

		if (!details.formats)
		{
			SDL_OutOfMemory();
			details.formatsLength = 0;
			details.presentModesLength = 0;
			return details;
		}

		result = renderer->vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, details.formats);
		if (result != VK_SUCCESS)
		{
			SDL_LogError(
				SDL_LOG_CATEGORY_APPLICATION,
				"vkGetPhysicalDeviceSurfaceFormatsKHR: %s\n",
				VkErrorMessages(result)
			);
		}
	}

	uint32_t presentModeCount;
	renderer->vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, NULL);

	if (presentModeCount != 0)
	{
		details.presentModes = SDL_malloc(sizeof(VkPresentModeKHR) * presentModeCount);
		details.presentModesLength = presentModeCount;

		if (!details.presentModes)
		{
			SDL_OutOfMemory();
			details.formatsLength = 0;
			details.presentModesLength = 0;
			return details;
		}

		result = renderer->vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, details.presentModes);
		if (result != VK_SUCCESS)
		{
			SDL_LogError(
				SDL_LOG_CATEGORY_APPLICATION,
				"vkGetPhysicalDeviceSurfacePresentModesKHR: %s\n",
				VkErrorMessages(result)
			);
		}
	}

	return details;
}

/* we want a physical device that is dedicated and supports our features */
static uint8_t IsDeviceIdeal(
	FNAVulkanRenderer *renderer,
	VkPhysicalDevice physicalDevice,
	const char** requiredExtensionNames,
	uint32_t requiredExtensionNamesLength,
	VkSurfaceKHR surface,
	QueueFamilyIndices* queueFamilyIndices
) {
	queueFamilyIndices->graphicsFamily = UINT32_MAX;
	queueFamilyIndices->presentFamily = UINT32_MAX;

	VkPhysicalDeviceProperties deviceProperties;
	renderer->vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);

	if (deviceProperties.deviceType != VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
	{
		return 0;
	}

	if (!CheckDeviceExtensionSupport(renderer, physicalDevice, requiredExtensionNames, requiredExtensionNamesLength))
	{
		return 0;
	}

	uint32_t queueFamilyCount;
	renderer->vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, NULL);

	if (queueFamilyCount == 0)
	{
		return 0;
	}

	SwapChainSupportDetails swapChainSupportDetails = QuerySwapChainSupport(renderer, physicalDevice, surface);
	if (swapChainSupportDetails.formatsLength == 0 && swapChainSupportDetails.presentModesLength == 0)
	{
		return 0;
	}

	VkQueueFamilyProperties queueProps[queueFamilyCount];
	renderer->vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueProps);

	for (uint32_t i = 0; i < queueFamilyCount; i++) {
		VkBool32 supportsPresent;
		renderer->vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &supportsPresent);
		if (supportsPresent && (queueProps[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0) {
			queueFamilyIndices->graphicsFamily = i;
			queueFamilyIndices->presentFamily = i;
			return 1;
		}
	}

	return 0;
}

/* if no dedicated device exists, one that supports our features would be fine */
static uint8_t IsDeviceSuitable(
	FNAVulkanRenderer *renderer,
	VkPhysicalDevice physicalDevice,
	const char** requiredExtensionNames,
	uint32_t requiredExtensionNamesLength,
	VkSurfaceKHR surface,
	QueueFamilyIndices* queueFamilyIndices
) {
	queueFamilyIndices->graphicsFamily = UINT32_MAX;
	queueFamilyIndices->presentFamily = UINT32_MAX;

	if (!CheckDeviceExtensionSupport(renderer, physicalDevice, requiredExtensionNames, requiredExtensionNamesLength))
	{
		return 0;
	}

	VkPhysicalDeviceProperties deviceProperties;
	renderer->vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);

	uint32_t queueFamilyCount;
	renderer->vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, NULL);

	if (queueFamilyCount == 0)
	{
		return 0;
	}

	SwapChainSupportDetails swapChainSupportDetails = QuerySwapChainSupport(renderer, physicalDevice, surface);
	if (swapChainSupportDetails.formatsLength == 0 && swapChainSupportDetails.presentModesLength == 0)
	{
		return 0;
	}

	VkQueueFamilyProperties queueProps[queueFamilyCount];
	renderer->vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &queueFamilyCount, queueProps);

	for (uint32_t i = 0; i < queueFamilyCount; i++) {
		VkBool32 supportsPresent;
		renderer->vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, i, surface, &supportsPresent);
		if (supportsPresent && (queueProps[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0) {
			queueFamilyIndices->graphicsFamily = i;
			queueFamilyIndices->presentFamily = i;
			return 1;
		}
	}

	return 0;
}

static uint8_t CheckValidationLayerSupport(
	const char** validationLayers,
	uint32_t length
) {
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, NULL);

	VkLayerProperties availableLayers[layerCount];
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);

	for (uint32_t i = 0; i < length; i++)
	{
		uint8_t layerFound = 0;

		for (uint32_t j = 0; j < layerCount; j++)
		{
			if (SDL_strcmp(validationLayers[i], availableLayers[j].layerName) == 0)
			{
				layerFound = 1;
				break;
			}
		}

		if (!layerFound)
		{
			return 0;
		}
	}

	return 1;
}

static VkSurfaceFormatKHR ChooseSwapSurfaceFormat(
	FNA3D_SurfaceFormat desiredSurfaceFormat,
	VkSurfaceFormatKHR *availableFormats,
	uint32_t availableFormatsLength
) {
	/* TODO: format mapping */

	SDL_LogInfo(
		SDL_LOG_CATEGORY_APPLICATION,
		"%s\n",
		"Could not find desired swap surface format, falling back to first available"
	);

	return availableFormats[0];
}

static VkPresentModeKHR ChooseSwapPresentMode(
	FNA3D_PresentInterval desiredPresentInterval,
	VkPresentModeKHR *availablePresentModes,
	uint32_t availablePresentModesLength
) {
	if (	desiredPresentInterval == FNA3D_PRESENTINTERVAL_DEFAULT ||
			desiredPresentInterval == FNA3D_PRESENTINTERVAL_ONE	)
	{
		for (uint32_t i = 0; i < availablePresentModesLength; i++)
		{
			if (availablePresentModes[i] == VK_PRESENT_MODE_FIFO_RELAXED_KHR)
			{
				return VK_PRESENT_MODE_FIFO_RELAXED_KHR;
			}
		}
	}
	else if (desiredPresentInterval == FNA3D_PRESENTINTERVAL_TWO)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"%s\n",
			"FNA3D_PRESENTINTERVAL_TWO not supported in Vulkan"
		);
	}
	else // FNA3D_PRESENTINTERVAL_IMMEDIATE
	{
		for (uint32_t i = 0; i < availablePresentModesLength; i++)
		{
			if (availablePresentModes[i] == VK_PRESENT_MODE_IMMEDIATE_KHR)
			{
				return VK_PRESENT_MODE_IMMEDIATE_KHR;
			}
		}
	}

	SDL_LogInfo(
		SDL_LOG_CATEGORY_APPLICATION,
		"%s\n",
		"Could not find desired presentation interval, falling back to VK_PRESENT_MODE_FIFO_KHR"
	);

	return VK_PRESENT_MODE_FIFO_KHR;
}

static VkExtent2D ChooseSwapExtent(
	const VkSurfaceCapabilitiesKHR capabilities,
	uint32_t width,
	uint32_t height
) {
	if (capabilities.currentExtent.width != UINT32_MAX)
	{
		return capabilities.currentExtent;
	}
	else
	{
		VkExtent2D actualExtent = { width, height };

		actualExtent.width = SDL_max(
			capabilities.minImageExtent.width,
			SDL_min(
				capabilities.maxImageExtent.width,
				actualExtent.width
			)
		);

		actualExtent.height = SDL_max(
			capabilities.minImageExtent.height,
			SDL_min(
				capabilities.maxImageExtent.height,
				actualExtent.height
			)
		);

		return actualExtent;
	}
}

FNA3D_Device* VULKAN_CreateDevice(
	FNA3D_PresentationParameters *presentationParameters,
	uint8_t debugMode
) {
	/* TODO */
	FNAVulkanRenderer *renderer;
	FNA3D_Device *result;
	VkResult vulkanResult;
	VkInstance instance;
	VkSurfaceKHR surface;
	uint32_t physicalDeviceCount;
	VkPhysicalDevice physicalDevice;
	VkDevice logicalDevice;
	VkQueue graphicsQueue;
	VkQueue presentQueue;
	VkCommandPool commandPool;
	uint32_t instanceExtensionCount;
	const char **instanceExtensionNames = NULL;

	/* Create the FNA3D_Device */
	result = (FNA3D_Device*) SDL_malloc(sizeof(FNA3D_Device));
	ASSIGN_DRIVER(VULKAN)

	/* Init the FNAVulkanRenderer */
	renderer = (FNAVulkanRenderer*) SDL_malloc(sizeof(FNAVulkanRenderer));
	SDL_memset(renderer, '\0', sizeof(FNAVulkanRenderer));

	/* load library so we can load vk functions dynamically */
	SDL_Vulkan_LoadLibrary(NULL);
	LoadGlobalFunctions();

	/* The FNA3D_Device and OpenGLDevice need to reference each other */
	renderer->parentDevice = result;
	result->driverData = (FNA3D_Renderer*) renderer;

	/* create instance */
	VkApplicationInfo appInfo = { VK_STRUCTURE_TYPE_APPLICATION_INFO };
	appInfo.pApplicationName = "FNA";
	appInfo.apiVersion = VK_MAKE_VERSION(1, 2, 136);

	if (
		!SDL_Vulkan_GetInstanceExtensions(
			presentationParameters->deviceWindowHandle,
			&instanceExtensionCount,
			NULL
		)
	) {
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"SDL_Vulkan_GetInstanceExtensions(): getExtensionCount: %s\n",
			SDL_GetError()
		);
		return NULL;
	}

    instanceExtensionNames = SDL_malloc(sizeof(const char *) * instanceExtensionCount);
	if (!instanceExtensionNames)
	{
        SDL_OutOfMemory();
        return NULL;
	}

	if (
		!SDL_Vulkan_GetInstanceExtensions(
			presentationParameters->deviceWindowHandle,
			&instanceExtensionCount,
			instanceExtensionNames
		)
	) {
		SDL_free((void*)instanceExtensionNames);
        SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"SDL_Vulkan_GetInstanceExtensions(): getExtensions %s\n",
			SDL_GetError()
		);
		return NULL;
	}

	if (!CheckInstanceExtensionSupport(instanceExtensionNames, instanceExtensionCount))
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"%s",
			"Required Vulkan instance extensions not supported"
		);

		return NULL;
	}

	/* create info structure */

	VkInstanceCreateInfo createInfo = { VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };

	char const* layerNames[] = { "VK_LAYER_KHRONOS_validation" };
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = instanceExtensionCount;
	createInfo.ppEnabledExtensionNames = instanceExtensionNames;
	createInfo.ppEnabledLayerNames = layerNames;

	if (debugMode)
	{
		createInfo.enabledLayerCount = sizeof(layerNames)/sizeof(layerNames[0]);
		if (!CheckValidationLayerSupport(layerNames, createInfo.enabledLayerCount))
		{
			SDL_LogWarn(
				SDL_LOG_CATEGORY_APPLICATION,
				"%s",
				"Validation layers not found, continuing without validation"
			);

			createInfo.enabledLayerCount = 0;
		}
	}
	else
	{
		createInfo.enabledLayerCount = 0;
	}

	vulkanResult = vkCreateInstance(&createInfo, NULL, &instance);
	SDL_free((void*)instanceExtensionNames);
	if (vulkanResult != VK_SUCCESS)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"vkCreateInstance failed: %s\n",
			VkErrorMessages(vulkanResult)
		);

		return NULL;
	}

	/* create surface */

	if (
		!SDL_Vulkan_CreateSurface(
			presentationParameters->deviceWindowHandle,
			instance,
			&surface
		)
	) {
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"SDL_Vulkan_CreateSurface failed: %s\n",
			SDL_GetError()
		);

		return NULL;
	}

	/* assign the instance and load function entry points */

	renderer->instance = instance;
	LoadInstanceFunctions(renderer);

	/* designate required device extensions */

	char const* deviceExtensionNames[] = { "VK_KHR_swapchain" };
	uint32_t deviceExtensionCount = sizeof(deviceExtensionNames)/sizeof(deviceExtensionNames[0]);

	/* determine a suitable physical device */

	vulkanResult = renderer->vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, NULL);
	if (vulkanResult != VK_SUCCESS)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"vkEnumeratePhysicalDevices failed: %s\n",
			VkErrorMessages(vulkanResult)
		);

		return NULL;
	}

	if (physicalDeviceCount == 0)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"Failed to find any GPUs with Vulkan support\n"
		);
		return NULL;
	}

	VkPhysicalDevice physicalDevices[physicalDeviceCount];

	vulkanResult = renderer->vkEnumeratePhysicalDevices(instance, &physicalDeviceCount, physicalDevices);
	if (vulkanResult != VK_SUCCESS)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"vkEnumeratePhysicalDevices failed: %s\n",
			VkErrorMessages(vulkanResult)
		);

		return NULL;
	}

	QueueFamilyIndices queueFamilyIndices;
	uint8_t physicalDeviceAssigned = 0;
	for (int i = 0; i < physicalDeviceCount; i++)
	{
		if (IsDeviceIdeal(renderer, physicalDevices[i], deviceExtensionNames, deviceExtensionCount, surface, &queueFamilyIndices))
		{
			physicalDevice = physicalDevices[i];
			physicalDeviceAssigned = 1;
			break;
		}
	}

	if (!physicalDeviceAssigned)
	{
		for (int i = 0; i < physicalDeviceCount; i++)
		{
			if (IsDeviceSuitable(renderer, physicalDevices[i], deviceExtensionNames, deviceExtensionCount, surface, &queueFamilyIndices))
			{
				physicalDevice = physicalDevices[i];
				physicalDeviceAssigned = 1;
				break;
			}
		}
	}

	if (!physicalDeviceAssigned)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"No suitable physical devices found."
		);

		return NULL;
	}

	/* Setting up Queue Info */
	int queueInfoCount = 1;
	VkDeviceQueueCreateInfo queueCreateInfos[2];
	float queuePriority = 1.0f;

	VkDeviceQueueCreateInfo queueCreateInfoGraphics = { VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO };
	queueCreateInfoGraphics.queueFamilyIndex = queueFamilyIndices.graphicsFamily;
	queueCreateInfoGraphics.queueCount = 1;
	queueCreateInfoGraphics.pQueuePriorities = &queuePriority;

	queueCreateInfos[0] = queueCreateInfoGraphics;

	if (queueFamilyIndices.presentFamily != queueFamilyIndices.graphicsFamily)
	{
		VkDeviceQueueCreateInfo queueCreateInfoPresent = { VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO };
		queueCreateInfoPresent.queueFamilyIndex = queueFamilyIndices.presentFamily;
		queueCreateInfoPresent.queueCount = 1;
		queueCreateInfoPresent.pQueuePriorities = &queuePriority;

		queueCreateInfos[1] = queueCreateInfoPresent;
		queueInfoCount++;
	}

	/* specifying used device features */
	/* empty for now because i don't know what we need yet... --cosmonaut */
	VkPhysicalDeviceFeatures deviceFeatures = {};

	/* creating the logical device */

	VkDeviceCreateInfo deviceCreateInfo = { VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO };
	deviceCreateInfo.queueCreateInfoCount = queueInfoCount;
	deviceCreateInfo.pQueueCreateInfos = queueCreateInfos;
	deviceCreateInfo.pEnabledFeatures = &deviceFeatures;
	deviceCreateInfo.ppEnabledExtensionNames = deviceExtensionNames;
	deviceCreateInfo.enabledExtensionCount = deviceExtensionCount;

	vulkanResult = renderer->vkCreateDevice(physicalDevice, &deviceCreateInfo, NULL, &logicalDevice);
   	if (vulkanResult != VK_SUCCESS)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"vkCreateDevice failed: %s\n",
			VkErrorMessages(vulkanResult)
		);

		return NULL;
	}

	/* assign logical device to the renderer and load entry points */

	renderer->logicalDevice = logicalDevice;
	LoadDeviceFunctions(renderer);

	renderer->vkGetDeviceQueue(logicalDevice, queueFamilyIndices.graphicsFamily, 0, &graphicsQueue);
	renderer->vkGetDeviceQueue(logicalDevice, queueFamilyIndices.presentFamily, 0, &presentQueue);

	/* create swap chain */

	SwapChainSupportDetails swapChainSupportDetails = QuerySwapChainSupport(
		renderer,
		physicalDevice,
		surface
	);

	VkSurfaceFormatKHR surfaceFormat = ChooseSwapSurfaceFormat(
		presentationParameters->backBufferFormat,
		swapChainSupportDetails.formats,
		swapChainSupportDetails.formatsLength
	);

	VkPresentModeKHR presentMode = ChooseSwapPresentMode(
		presentationParameters->presentationInterval,
		swapChainSupportDetails.presentModes,
		swapChainSupportDetails.presentModesLength
	);

	VkExtent2D extent = ChooseSwapExtent(
		swapChainSupportDetails.capabilities,
		presentationParameters->backBufferWidth,
		presentationParameters->backBufferHeight
	);

	uint32_t imageCount = swapChainSupportDetails.capabilities.minImageCount + 1;

	if (	swapChainSupportDetails.capabilities.maxImageCount > 0 &&
			imageCount > swapChainSupportDetails.capabilities.maxImageCount	)
	{
		imageCount = swapChainSupportDetails.capabilities.maxImageCount;
	}

	VkSwapchainCreateInfoKHR swapChainCreateInfo = { VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR };
	swapChainCreateInfo.surface = surface;
	swapChainCreateInfo.minImageCount = imageCount;
	swapChainCreateInfo.imageFormat = surfaceFormat.format;
	swapChainCreateInfo.imageColorSpace = surfaceFormat.colorSpace;
	swapChainCreateInfo.imageExtent = extent;
	swapChainCreateInfo.imageArrayLayers = 1;
	swapChainCreateInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
	swapChainCreateInfo.preTransform = swapChainSupportDetails.capabilities.currentTransform;
	swapChainCreateInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	swapChainCreateInfo.presentMode = presentMode;
	swapChainCreateInfo.clipped = VK_TRUE;
	swapChainCreateInfo.oldSwapchain = VK_NULL_HANDLE;

	VkSwapchainKHR swapChain;
	vulkanResult = renderer->vkCreateSwapchainKHR(renderer->logicalDevice, &swapChainCreateInfo, NULL, &swapChain);
	if (vulkanResult != VK_SUCCESS)
	{
		SDL_LogError(
			SDL_LOG_CATEGORY_APPLICATION,
			"vkCreateSwapchainKHR: %s\n",
			VkErrorMessages(vulkanResult)
		);

		return NULL;
	}

	return result;
}

FNA3D_Driver VulkanDriver = {
	"Vulkan",
	VULKAN_PrepareWindowAttributes,
	VULKAN_GetDrawableSize,
	VULKAN_CreateDevice
};

#endif /* FNA_3D_DRIVER_VULKAN */
