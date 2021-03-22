workspace "Tetrahedron"
architecture "x86_64"
startproject "Tetrahedron"

configurations
{
    "Debug",
    "Release",
    "Dist"
}

flags
{
    "MultiProcessorCompile"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {""}

group "Dependencies"
group ""

include "tetra"
include "sandbox"