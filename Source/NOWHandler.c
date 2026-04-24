
void __thiscall NOWHandler(void *this,void *param_1)

{
  ParseNOW(*(void **)((int)this + 8),param_1);
  (**(code **)(*(int *)this + 0xe8))(param_1);
  return;
}

