
#pragma once

#include <reflectionzeug/base/Color.h>

#include <globjects/base/ref_ptr.h>
#include <globjects/Texture.h>

#include <gloperate/pipeline/AbstractPipeline.h>
#include <gloperate/pipeline/Data.h>

#include <gloperate/base/ColorGradientList.h>

namespace gloperate
{
	class AbstractTargetFramebufferCapability;
	class AbstractViewportCapability;
	class AbstractVirtualTimeCapability;
	class AbstractCameraCapability;
	class AbstractProjectionCapability;
	class AbstractTypedRenderTargetCapability;
}

class RasterizationStage;
class PostprocessingStage;


class PostprocessingPipeline : public gloperate::AbstractPipeline
{
public:
    PostprocessingPipeline();
    virtual ~PostprocessingPipeline();

    
public:
    gloperate::Data<gloperate::AbstractTargetFramebufferCapability *> targetFBO;
    gloperate::Data<gloperate::AbstractViewportCapability *> viewport;
    gloperate::Data<gloperate::AbstractVirtualTimeCapability *> time;
    gloperate::Data<gloperate::AbstractCameraCapability *> camera;
    gloperate::Data<gloperate::AbstractProjectionCapability *> projection;
    gloperate::Data<gloperate::AbstractTypedRenderTargetCapability *> renderTargets;

    gloperate::Data<std::string> gradientName;
    gloperate::Data<gloperate::ColorGradientList> gradients;
    gloperate::Data<globjects::ref_ptr<globjects::Texture>> gradientsTexture;
};
