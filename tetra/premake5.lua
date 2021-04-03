project "tetra"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

    pchheader "src/ttpch.h"
	pchsource "src/ttpch.cpp"

	files
	{
		"src/**/**.h",
		"src/**/**.cpp",
        "src/**/**.hpp"
	}

	defines
	{
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
        "vendor",
		"vendor/glfw/include"
	}

	links
	{
		"glfw"
	}

	filter "configurations:Debug"
		defines "TT_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TT_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TT_DIST"
		runtime "Release"
		optimize "on"