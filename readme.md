# TruHy Embedded C/C++ Tools (Eclipse IDE plugin)

## Overview

An Eclipse IDE plugin to provide New Project Wizards for the "Intel Cyclone V SoC FPGA" series chipset.  It is intended for the DE10-Nano FPGA development board.  This enables developers to easily create Eclipse IDE C projects that are pre-configured.

## The folders

| Folder                      | Description                        |
| ----------------------------| ---------------------------------- |
| truhy_intel_socfpga_plugin  | Plugin Eclipse IDE project         |
| truhy_intel_socfpga_feature | Plugin Eclipse IDE feature project |
| repository                  | Installable plugin                 |

## How to install the custom Eclipse IDE plugin

1. Visit [Eclipse IDE website](https://www.eclipse.org/downloads/) and download the installer and install "Eclipse IDE for Embedded C/C++ Developers"
2. In Eclipse IDE, use the "Install New Software..." to install the plugin.

See my tutorial at:
[https://truhy.co.uk](https://truhy.co.uk)

## Run-time dependencies

Plugin minimum requirements:
- JavaSE-11 or later
- CDT & Embedded CDT plugins

## Information for developers

## How to edit the plugin source code

- Download code as zip from Github, extract all to a folder of your choice
- Go to Eclipse IDE website to find how to install "Eclipse IDE for Embedded C/C++ Developers"
- Use the "Install New Software..." to install the "Eclipse Plug-in Development Environment" plugin.
- Open the source code plugin Eclipse IDE project from folder "truhy_intel_socfpga_plugin"
- Open the source code feature Eclipse IDE project from folder "truhy_intel_socfpga_feature"

## How to generate the plugin

After making your changes, you will need to generate the plugin, this will produce files that are installable (deployable).  Surprisingly, exporting from the plugin project as a deployable plugin is useless.  This is because in later versions of Eclipse IDE, plugins can only install from a P2 Equinox repository.

Steps to export a deployable plugin as a repository:
1. In the feature project select from the menu "File/Export..."
2. In the dialog, select "Deployable Features"
3. Select your preferred destination
4. Go to "Options" tab, check "Categorize repository" and browse the category.xml file
5. Click "Finish" button

## Helpful references

Eclipse documentation:
[How to add project templates to CDT](https://help.eclipse.org/2023-06/index.jsp?topic=%2Forg.eclipse.cdt.doc.isv%2Fguide%2FprojectTemplateEngine%2FHowtodeveloptemplates.html&anchor=howto%2edevelop%2etemplates)
[What's New in CDT Build System 4.0](https://help.eclipse.org/2023-06/index.jsp?topic=%2Forg.eclipse.cdt.doc.isv%2Fguide%2Fcdt_build_system%2Fwhats_new%2F4.0%2Fwhats_new_CBS_40.html&cp%3D13_0_3)

Useful source codes:
[CDT processes source code](https://github.com/eclipse-cdt/cdt/tree/main/core/org.eclipse.cdt.core/templateengine/org/eclipse/cdt/core/templateengine/process/processes)
[Embed CDT templates](https://github.com/eclipse-embed-cdt/eclipse-plugins/tree/master/plugins)
[Embed CDT processes](https://github.com/eclipse-embed-cdt/eclipse-plugins/tree/master/plugins/org.eclipse.embedcdt.templates.core/src/org/eclipse/embedcdt/templates/core/processes)
