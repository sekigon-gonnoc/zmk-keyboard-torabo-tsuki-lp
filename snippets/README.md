# Snippetの組み合わせ

Snippetはモジュール種別ごとのフォルダにまとめています。フォルダ内のsnippet名とbuild.yamlで指定する名前は同じです。

- `trackball/`
- `trackpad/`
- `trackpad-mini/`
- `hires-dial/`
- `4-direction-switch/`

`dynamic-settings`や`split-central`などモジュール共通のsnippetは、この階層の直下に置いています。

各モジュールの構成を `hardware`、`input-path`、`settings` に分けています。
`input-path`の `from-left/right` は入力元の物理側を表します。受信snippetは
DongleとBLE centralで共通です。受信先はbuild targetで決まります。

## Trackball

| 役割 | snippet |
| --- | --- |
| センサー | `hardware-trackball` |
| 左側をローカル処理 | `input-path-trackball-local-left` |
| 右側をローカル処理 | `input-path-trackball-local-right` |
| 左側Peripheralから送信 (`reg = <0>`) | `input-path-trackball-send-from-left` |
| 右側Peripheralから送信 (`reg = <1>`) | `input-path-trackball-send-from-right` |
| 左側の入力を受信 (`reg = <0>`) | `input-path-trackball-receive-from-left` |
| 右側の入力を受信 (`reg = <1>`) | `input-path-trackball-receive-from-right` |
| 設定 | `settings-trackball-left` / `settings-trackball-right` |

## Trackpad / Trackpad Mini

| 役割 | Trackpad | Trackpad Mini |
| --- | --- | --- |
| センサー | `hardware-trackpad` | `hardware-trackpad-mini` |
| 左右ローカル処理 | `input-path-trackpad-local-left/right` | `input-path-trackpad-mini-local-left/right` |
| 左側Peripheralから送信 (`reg = <0>`) | `input-path-trackpad-send-from-left` | `input-path-trackpad-mini-send-from-left` |
| 右側Peripheralから送信 (`reg = <1>`) | `input-path-trackpad-send-from-right` | `input-path-trackpad-mini-send-from-right` |
| 左側の入力を受信 (`reg = <0>`) | `input-path-trackpad-receive-from-left` | `input-path-trackpad-mini-receive-from-left` |
| 右側の入力を受信 (`reg = <1>`) | `input-path-trackpad-receive-from-right` | `input-path-trackpad-mini-receive-from-right` |
| 設定 | `settings-trackpad-left/right` | `settings-trackpad-mini-left/right` |

## HIRES Dial

| 役割 | snippet |
| --- | --- |
| 物理センサーとボタン | `hardware-hires-dial` |
| 左側でローカル使用 | `input-path-hires-dial-local-left` |
| 右側でローカル使用 | `input-path-hires-dial-local-right` |
| 左側Peripheralから送信 | `input-path-hires-dial-send-from-left` |
| 右側Peripheralから送信 | `input-path-hires-dial-send-from-right` |
| 左側の入力を受信 | `input-path-hires-dial-receive-from-left` |
| 右側の入力を受信 | `input-path-hires-dial-receive-from-right` |
| 設定 | `settings-hires-dial-left` / `settings-hires-dial-right` |

HIRES Dialのsensor event送信はZMK splitが内部で行うため、
送信path snippetは意図的に空です。ZMK splitがsensor eventを自動転送しますが、
snippetの組み合わせで送信経路を明示するために選択します。

## 4-direction-switch

物理switchには `hardware-4-direction-switch` と `input-path-4-direction-switch-local` を
組み合わせます。Peripheral側のswitch入力を受け取るBLE centralまたはDongleでは、
`input-path-4-direction-switch-receive-from-peripheral` を選びます。このモジュールにDynamic Settingsはありません。

## Double ballの例

左側のトラックボールをcentralで使い、右側Peripheralからの入力も受信する場合:

```yaml
snippet: >-
  studio-rpc-usb-uart split-central dynamic-settings
  hardware-trackball input-path-trackball-local-left settings-trackball-left
  input-path-trackball-receive-from-right settings-trackball-right
```

右側Peripheral:

```yaml
snippet: >-
  hardware-trackball input-path-trackball-send-from-right
```

Dongleで左右を受信する場合:

```yaml
snippet: >-
  studio-rpc-usb-uart dynamic-settings
  input-path-trackball-receive-from-left settings-trackball-left
  input-path-trackball-receive-from-right settings-trackball-right
```
