# <font size = 7>**Hotel-Management-System Document**</font>
&nbsp;
## <font size = 6>Catalog</font>

> + [BackgroundSystem](#backgroundsystem)
> + [Dish](#dish)
> + [Dishes](#dishes)
> + [DishInfo](#dishinfo)
> + [Kitchen](#kitchen)
> + [Menu](#menu)
> + [Order](#order)
> + [OrderInfo](#orderinfo)
> + [OrderLibrary](#orderlibrary)
> + [OrderSolver](#ordersolver)
> + [StaffManager](#staffmanager)
> + [Storage](#storage)


---

## <font size = 6>BackgroundSystem</font>

```
后台系统类。系统逻辑层对外接口之一，可以通过此接口进行系统的员工打卡、库存管理、菜品管理以及历史订单查询操作。
```
### Functions

+ <font size = 4>**public bool SignIn(int ID)**</font>
> + **description**
> 	员工签到
> 
> + **parameters**
> 	+ ID: 员工的工号
> 	
> + **return**
> 	若签退成功，则返回true，否则返回false。

+ <font size = 4>**public bool SignOut(int ID)**</font>
> + **description**
> 	员工签退
> 
> + **parameters**
> 	+ ID: 员工的工号
> 	
> + **return**
> 	若签退成功，则返回true，否则返回false。

+ <font size = 4>**public void AddMaterialsToStorage(map\<string, int> materials)**</font>
> + **description**
> 	添加食材至库存中
> 
> + **parameters**
> 	+ metarials: 要添加的食材的表单
> 		+ key: 食材名称
> 		+ value: 食材的数量

+ <font size = 4>**public OrderInfo GetOrderInfo(int orderID)**</font>
> + **description**
> 	根据订单编号获取历史订单信息
> 	
> + **parameters**
> 	+ orderID: 订单编号
> 	
> + **return**
> 	获取到的订单信息

+ <font size = 4>**public vector<OrderInfo> GetAllOrderInfo()**</font>
> + **description**
> 	获取所有的历史订单信息
> 	
> + **return**
> 	获取到的订单信息表单

+ <font size = 4>**public bool AddDishType(Dish dish)**</font>
> + **description**
> 	添加新的菜式
> 	
> + **parameters**
> 	+ dish: 要添加的菜式的信息
> 	
> + **return**
> 	若添加成功，则返回true，否则返回false。

+ <font size = 4>**public bool RemoveDishType(int dishID)**</font>
> + **description**
> 	移除已存在的菜式
> 	
> + **parameters**
> 	+ dishID: 要移除的菜品的菜品编号
> 	
> + **return**
> 	若移除成功，则返回true，否则返回false。

---
&nbsp;

## <font size = 6>Dish</font>
```
菜品类。用于存储一个菜品的信息。
```
### Properties

+ <font size = 4>**string Name**</font>
> + **description**
> 	菜品的名称

+ <font size = 4>**map\<string, name> MaterialsList**</font>
> + **description**
> 	菜品的原材料清单
> 	
> + **TKey**
> 	食材名称
> 	
> + **TValue**
> 	食材的数量

+ <font size = 4>**int Price**</font>
> + **description**
> 	菜品的单价

+ <font size = 4>**string Description**</font>
> + **description**
> 	菜品的描述

---
&nbsp;

## <font size = 6>Dishes</font>
```
菜品管理类。用于管理菜品表单，并记录菜品的可用情况。应可通过此类修改或添加菜式。
```
### Functions

+ <font size = 4>public bool CheckDishState(int dishID)</font>
> + **description**
> 	检查菜品可用情况
> 	
> + **parameters**
> 	+ dishID: 菜品编号
> 	
> + **return**
> 	若库存充足，菜品可用，则返回true，否则返回false。

+ <font size = 4>public int AddDishType(Dish dish)</font>
> + **description**
> 	添加菜式
> 	
> + **parameters**
> 	+ dish: 菜品
> 	
> + **return**
> 	新添加的菜式的菜品编号

+ <font size = 4>public bool RemoveDishType(int dishID)</font>
> + **description**
> 	移除菜式
> 
> + **parameters**
> 	+dishID: 菜品编号
> 	
> + **return**
> 	若成功移除，返回true，否则返回false

+ <font size = 4>public vector\<DishInfo> GetDishesList()</font>
> + **description**
> 	获取菜品表单
> 	
> + **return**
> 	返回获取到的菜品表单

---
&nbsp;

## <font size = 6>DishInfo</font>
```
菜品信息类。用于存储一种菜品的信息以及当前的可用状态。
```
### Properties

+ <font size = 4>**int DishID**</font>
> + **description**
> 	菜品编号

+ <font size = 4>**bool IsAvailable**</font>
> + **description**
> 	菜品的可用状态

+ <font size = 4>**string Name**</font>
> + **description**
> 	菜品的名称

+ <font size = 4>**map\<string, name> MaterialsList**</font>
> + **description**
> 	菜品的原材料清单
> 	
> + **TKey**
> 	食材名称
> 	
> + **TValue**
> 	食材的数量

+ <font size = 4>**int Price**</font>
> + **description**
> 	菜品的单价

+ <font size = 4>**string Description**</font>
> + **description**
> 	菜品的描述

---
&nbsp;

## <font size = 6>Kitchen</font>
```
厨房类。系统逻辑层对外接口之一，会接收菜品制作请求，且在菜品处理完成后进行汇报。
```

### Functions

+ <font size = 4>**public void AddTask(int orderID, int dishID)**</font>
> + **description**
> 	添加菜品制作任务
> 
> + **parameters**
> 	+ orderID: 订单编号
> 	+ dishID: 菜品编号

+ <font size = 4>**public void FinishTask(int orderID, int dishID)**</font>
> + **description**
> 	当菜品制作完成时，调用此方法。
> 	
> + **parameters**
> 	+ orderID: 订单编号
> 	+ dishID: 菜品编号


---
&nbsp;

## <font size = 6>Menu</font>
```
菜单类。系统逻辑层对外接口之一，可以通过此类获取菜单以及创建订单。
```
### Functions

+ <font size = 4>**public vector\<DishInfo> GetDishesList()**</font>
> + **description**
> 	获取由所有可用菜品组成的菜单
> 	
> + **return**
> 	获取到的可用的菜品清单

+ <font size = 4>**public bool CreateOrder(map\<int, int> dishes, int creatorID )**</font>
> + **description**
> 	创建订单
> 	
> + **parameters**
> 	+ dishes: 菜品清单
> 		+ key: 菜品编号
> 		+ value: 菜品的数量
> 	+ creatorID: 订单创建者的编号
> 	
> + **return**
> 	若订单创建成功，返回true，否则返回false。

+ <font size = 4>**public void OnDishDelivered(int orderID, int dishID)**</font>
> + **description**
> 	当一份菜品已被呈递给顾客时，调用此方法以更新订单状态。
> 	
> + **parameter**
> 	+ orderID: 订单编号
> 	+ dishID: 菜品编号


---
&nbsp;

## <font size = 6>Order</font>
```
订单类。用于记录与更新处理中的订单的状态与信息。
```

### Functions

+ <font size = 4>**public void OnDishFinished(int dishID)**</font>
> + **description**
> 	完成菜品时调用，更新订单的状态信息
>
> + **parameters**
> 	+ dishID: 菜品号

+ <font size = 4>**public OrderInfo GenerateOrderInfo()**</font>
> + **description**
> 	生成订单信息
>   
> + **return**
> 	返回值为订单的信息。

+ <font size = 4>**public bool GetOrderState()**</font>
> + **description**
> 	获取订单状态

---
&nbsp;

## <font size = 6>OrderInfo</font>
```
订单信息类。用于储存订单信息。
```
### Properties

+ <font size = 4>**int OrderID**</font>
> + **description**
> 	订单编号

+ <font size = 4>**map\<int, int> DishesList**</font>
> + **description**
> 	订单中菜品的列表
> + **TKey**
> 	菜品号
> + **TValue**
> 	菜品数量

+ <font size = 4>**int Price**</font>
> + **description**
> 	订单的总价 

+ <font size = 4>**int Creator**</font>
> + ** description**
> 	订单创建者的工号

---
&nbsp;

## <font size = 6>OrderLibrary</font>
```
订单库管理类。用于管理与查询历史订单信息，（每一个订单信息应存有其订单状态、菜品、总价与订单创建者）。可通过此类添加已完成的订单信息，或根据订单编号查询指定的历史订单信息。
```
### Functions

+ <font size = 4>**void AddOrderInfo(OrderInfo orderInfo)**</font>
> + **description**
>   添加新的订单记录
>
> + **parameters**
>	+ orderInfo: 订单信息

+ <font size = 4>**OrderInfo GetOrderInfo(int orderID)**</font>
> + **description**
> 	根据订单号获取订单信息
> 	
> + **parameters**
> 	+ orderID: 订单编号

---
&nbsp;

## <font size = 6>OrderSolver</font>
```
订单处理类。此类会接收订单创建请求，并对新创建出来的订单进行处理，在订单完成之后会将订单添加到历史订单库中。
```
### Functions

+ <font size = 4>**public int CreateOrder(map\<int, int> dishesList, int creatorID)**</font>
> + **description**
> 	创建新的订单。创建后就会开始订单处理流程。
> + **parameters**
> 	+ dishesList: 菜品列表。
> 		+ key: 菜品编号
> 		+ value: 数量
> 	+ creatorID: 创建者工号。
> + **return**
> 	新创建的订单的编号，如果创建失败则返回-1。

+ <font size = 4>**public void OnDishCooked(int orderID, int dishID)**</font>
> + **description**
> 	当一个菜品在厨房被烹饪好后，此方法应被调用。
> + **parameters**
> 	+ orderID: 订单编号
> 	+ dishID: 菜品编号

+ <font size = 4>**public void OnDishDelivered(int orderID, int dishID)**</font>
> + **description**
> 	当一个菜品被服务员呈递给顾客后，此方法应被调用。
> + **parameters**
> 	+ orderID: 订单编号
> 	+ dishID: 菜品编号

---
&nbsp;

## <font size = 6>StaffManager</font>

```
员工管理类。用于管理员工状态与接收员工分配请求，并及时地分配负责各个菜品的服务员。
```
### Functions

+ <font size = 4>**public bool AddStaff(int id)**</font>
> + **description**
>   向系统中增加新的可用员工
>
> + **parameters**
>	+ id: 员工的工号
> 
> + **return**
> 	当添加成功时，返回true，否则返回false。

+ <font size = 4>**public bool RemoveStaff(int id)**</font>
> + **description**
> 	从系统中移除可用员工
>
> + **parameters**
>	+ id: 员工的工号
>
> + **return**
> 	当成功移除员工时，返回true，否则返回false。

+ <font size = 4>**public void AddTask(int orderID, int dishID)**</font>
> + **description**
> 	添加新的任务，并由此类自动将任务分配给服务员
>
> + **parameters**
>	+ orderID: 订单编号
>	+ dishID: 菜品编号

+ <font size = 4>**public void OnTaskFinished(int orderID, int dishID)**</font>
> + **description**
>   通知员工管理系统某个任务已完成。
>
> + **parameters**
>	+ orderID: 订单编号
>	+ dishID: 菜品编号

---
&nbsp;

## <font size = 6>Storage</font>
```
库存类。用于管理目前的食材库存，可通过此类进行食材情况的查询以及食材库存的管理。
```
### Functions

+ <font size = 4>**public void AddMaterial(string name, int num)**</font>
> + **description**
> 向库存中添加食材
> + **parameters**
>	+ name: 需要添加的食材的名称
>	+ num: 需要添加的食材的数量

+ <font size = 4>**public void TakeMaterial(string name, int num)**</font>
> + **description**
> 从库存中移除食材
> + **parameters**
> 	+ name: 目标食材的名称
> 	+ num: 需要移除的数量


---
&nbsp;