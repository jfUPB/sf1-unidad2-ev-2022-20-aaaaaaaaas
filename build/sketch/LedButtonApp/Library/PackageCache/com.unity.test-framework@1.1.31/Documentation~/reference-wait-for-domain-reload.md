#line 1 "/home/pop-os/Interactivos/Unidad2/sf1-unidad2-ev-2022-20-aaaaaaaaas/sf1-unidad2-ev-2022-20-aaaaaaaaas/LedButtonApp/Library/PackageCache/com.unity.test-framework@1.1.31/Documentation~/reference-wait-for-domain-reload.md"
# WaitForDomainReload
`WaitForDomainReload` is an [IEditModeTestYieldInstruction](./reference-custom-yield-instructions.md) that you can yield in Edit Mode tests. It delays the execution of scripts until after an incoming domain reload. If the domain reload results in a script compilation failure, then it throws an exception.

## Constructors

| Syntax                       | Description                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| `WaitForDomainReload()` | Create a new instance of the `WaitForDomainReload` yield instruction. |

## Example
``` C@
[UnitySetUp]
public IEnumerator SetUp()
{
    File.Copy("Resources/MyDll.dll", @"Assets/MyDll.dll", true); // Trigger a domain reload.
    AssetDatabase.Refresh();
    yield return new WaitForDomainReload();
}
```