# Snippetの組み合わせ

Snippetはモジュール種別ごとのフォルダにまとめています。フォルダ内のsnippet名とbuild.yamlで指定する名前は同じです。

- `trackball/`
- `trackpad/`
- `trackpad-mini/`
- `hires-dial/`
- `4-direction-switch/`
- `nemu-link-mic/`

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
| ポインタ処理設定 | `settings-trackball-left` / `settings-trackball-right` |
| PAW3222 sensor設定 | `settings-paw3222-left` / `settings-paw3222-right` |

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

## Nemu-link microphone

| 役割 | snippet |
| --- | --- |
| PDMマイクと `&mic` behavior | `hardware-nemu-link-mic` |
| 左右側からESB送信、PTT有効 | `input-path-nemu-link-mic-send-from-left/right` |
| Dongleで左右側音声を受信してUSB Audioへ出力 | `input-path-nemu-link-mic-receive-from-left/right` |
| owner/proxy向けDynamic Settings schema (left) | `settings-nemu-link-mic-left` |
| owner/proxy向けDynamic Settings schema (right) | `settings-nemu-link-mic-right` |

Peripheral:

```yaml
snippet: hardware-nemu-link-mic input-path-nemu-link-mic-send-from-right
```

送信元の側に応じて `send-from-left` / `send-from-right` を使います。
Dongleは対応する `receive-from-left` / `receive-from-right` を追加します。
受信先はUSB Audio Class 1です。StudioでPTTキーを割り当てる場合は、
`hardware-nemu-link-mic` が追加する `&mic` behaviorを選択します。
micの接続先は `CONFIG_ZMK_NEMU_LINK_MIC_SOURCE` で指定し、Studio接続先の
`CONFIG_ZMK_NEMU_LINK_STUDIO_SOURCE` とは独立しています。

## Double ballの例

左側のトラックボールをcentralで使い、右側Peripheralからの入力も受信する場合:

```yaml
snippet: >-
  studio-rpc-usb-uart split-central dynamic-settings
  hardware-trackball input-path-trackball-local-left settings-trackball-left settings-paw3222-left
  input-path-trackball-receive-from-right settings-trackball-right
```

右側Peripheral:

```yaml
snippet: >-
  hardware-trackball input-path-trackball-send-from-right settings-paw3222-right
```

Dongleで左右を受信する場合:

```yaml
snippet: >-
  studio-rpc-usb-uart dynamic-settings
  input-path-trackball-receive-from-left settings-trackball-left
  input-path-trackball-receive-from-right settings-trackball-right
```
