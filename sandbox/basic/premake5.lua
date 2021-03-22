project "sandbox-basic"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
        "src/**.hpp"
	}

	includedirs
	{
		"%{wks.location}/tetra/src",
        "%{wks.location}/tetra/vendor"
	}

	links
	{
		"tetra"
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
