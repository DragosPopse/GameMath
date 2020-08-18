outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "GameMath"
    configurations
    {
        "Debug",
        "Release"
    }
    platforms
    {
        "Win32",
        "Win64"
    }

project "GameMath"
    kind "ConsoleApp"

    language "C++"
    cppdialect "C++17"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.location}/tests/**.cpp",
        "%{prj.location}/tests/**.h",
        "%{prj.location}/tests/**.hpp",
        "%{prj.location}/include/**.h",
        "%{prj.location}/include/**.hpp"
    }

    includedirs
    {
        "%{prj.location}/include"
    }

    warnings "Extra"

    filter "platforms:Win32"
        architecture "x86"
        
    filter "platforms:Win64"
        architecture "x86_64"

    filter "configurations:Debug"
        symbols "On"
        runtime "Debug"

    filter "configurations:Release"
        optimize "Full"
        runtime "Release"

