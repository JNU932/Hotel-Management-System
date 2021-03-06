# <font size = 7>**Hotel-Management-System Document**</font>

## Catalog

> + [Storage](###Strorage)
> + [OrderManager](###OrderManager)
> + [StaffManager](###StaffManager)
> + [OrderSolver](###OrderSolver)
> + [Dishes](###Dishes)
> + [Menu](###Menu)
> + [Kitchen](###Kitchen)
> + [BackgroundSystem](###BackgroundSystem)

---
## <font size = 6>Storage</font>
```
库存类。用于管理目前的食材库存，可通过此类进行食材情况的查询以及食材库存的管理。
```
### Functions
+ <font size = 4>**public void AddMaterial**</font>
> + **description**
> 向库存中添加食材
> + **parameters**
>
>    | 参数名 | 参数类型 | 描述                 |
>    | ------ | -------- | -------------------- |
>    | name   | string   | 需要添加的食材的名称 |
>    | num    | int      | 需要添加的食材的数量 |
>
>   

+ <font size = 4>**public void TakeMaterial**</font>
> + **description**
> 从库存中移除食材
> + **parameters**
> 	
> 	- | 参数名 | 参数类型 | 描述                 |
> 	  | ------ | -------- | -------------------- |
> 	  | name   | string   | 需要移除的食材的名称 |
> 	  | num    | int      | 需要移除的食材的数量 |
> 	  
> 	  

---
&nbsp;
## <font size = 6>OrderManager</font>
```
订单库管理类。用于管理与查询历史订单信息，（每一个订单信息应存有其订单状态、菜品、总价与订单创建者）。可通过此类添加新创建的订单信息，标记已完成处理的订单信息，根据订单编号查询指定的历史订单。
```
---
&nbsp;

## <font size = 6>StaffManager</font>

```
员工管理类。用于管理员工状态与接收员工分配请求，并及时地分配负责各个菜品的服务员。
```
### Functions

+ <font size = 4>**public bool AddStaff**</font>

> + **description**
>   向系统中增加新的员工
>
> + **parameters**
>
>   | 参数名 | 参数类型 | 描述         |
>   | ------ | -------- | ------------ |
>   | name   | string   | 新员工的名称 |
> 
> + **return**
> 	当添加成功时，返回true，否则返回false。

&nbsp;
+ <font size = 4>**public bool RemoveStaff**</font>

> + **description**
> 	从系统中移除员工
>
> + **parameters**
>
> 	| 参数名 | 参数类型 | 描述               |
> 	| ------ | -------- | ------------------ |
> 	| name   | string   | 需要移除的员工姓名 |
>
> + **return**
> 	当成功移除员工时，返回true，否则返回false。

&nbsp;
+ <font size = 4>**public void AddTask**</font>

> + **description**
> 	添加新的任务，并由此类自动将任务分配给服务员
>
> + **parameters**
>
>   | 参数名  | 参数类型 | 描述     |
>   | ------- | -------- | -------- |
>   | message | string   | 任务信息 |



+ <font size = 4>**public void OnTaskFinished**</font>

> + **description**
>   通知员工管理系统某个任务已完成。
>
> + **parameters**
>
>   | 参数名  | 参数类型 | 描述     |
>   | ------- | -------- | -------- |
>   | message | string   | 任务信息 |

---
&nbsp;

## <font size = 6>StaffInfo</font>

```
员工信息类。用于存储员工信息及状态。
```
### Properties
+ <font size = 4>**ID**</font>

>   | 类型 | 描述     |
>   | -------- | -------- |
>   | int | 员工独一无二的工号 |
>   

+ <font size = 4>**Name**</font>

>| 类型   | 描述       |
>| ------ | ---------- |
>| string | 员工的姓名 |



---
&nbsp;
## <font size = 6>OrderSolver</font>

---
&nbsp;
## <font size = 6>Dishes</font>
---
&nbsp;

## <font size = 6>Menu</font>

---
&nbsp;
## <font size = 6>Kitchen</font>
---
&nbsp;

## <font size = 6>BackgroundSystem</font>
