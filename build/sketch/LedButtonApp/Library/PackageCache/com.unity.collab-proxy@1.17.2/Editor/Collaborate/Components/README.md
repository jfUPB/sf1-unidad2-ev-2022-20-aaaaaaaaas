#line 1 "/home/pop-os/Interactivos/Unidad2/sf1-unidad2-ev-2022-20-aaaaaaaaas/sf1-unidad2-ev-2022-20-aaaaaaaaas/LedButtonApp/Library/PackageCache/com.unity.collab-proxy@1.17.2/Editor/Collaborate/Components/README.md"
# Resources
This directory contains the UIElements-based user interface components.

## Overview
Each component is defined as its own class and file in this directory.

## Adding a New Component
Each component is a C# class that extends the UiElements' VisualElement class and provides a UXML factory. If no UXML
parameters are required/desired, a simple factory like this (taken from AlertBar) works:
```csharp
public new class UxmlFactory : UxmlFactory<AlertBar> { }
```
Just adding this line to the bottom of the component class with the `<AlertBar>` replaced with the name of the class.
Adding UXML parameters used to be covered in the official docs. Until it is returned: look at the source code for
any UiElements class such as TextElement.

To use the component in UXML (with editor inspections) the xml schema needs to be updated within the Unity Editor.
Instructions on how to do that is contained in `../Assets/`.
