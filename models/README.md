# Models

Place GGUF model weights in this directory.

A small instruction-tuned model recommended:

```bash
# Qwen2.5 1.5B instruct, Q4 quantization (~1 GB).
curl -L -o models/model.gguf \
  https://huggingface.co/Qwen/Qwen2.5-1.5B-Instruct-GGUF/resolve/main/qwen2.5-1.5b-instruct-q4_k_m.gguf
```

Any GGUF file works — pick a size that fits your RAM and latency budget.
