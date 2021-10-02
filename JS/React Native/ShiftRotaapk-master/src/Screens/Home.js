import React, { useState } from 'react'
import { View, Text,StyleSheet } from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createNativeStackNavigator } from '@react-navigation/native-stack';
import { Button } from 'react-native'
import DatePicker from 'react-native-date-picker'

const HomeScreen=()=>{
    const [date, setDate] = useState(new Date())
    const [open, setOpen] = useState(false)
   
    return (
      <View style={styles.container}>
        <Button title="Open" style={styles.open} onPress={() => setOpen(true)} />
        
        <DatePicker
          modal
          open={open}
          date={date}
          mode={"date"}
          onConfirm={(date) => {
            setOpen(false)
            setDate(date)
          }}
          onCancel={() => {
            setOpen(false)
          }}
        />
        { console.log(date.getDate())}
     
      </View>
      
        
    )
 }

 const styles=StyleSheet.create({
    open:{
        display:"flex",
        justifyContent:"center",
        width:10,
        backgroundColor:"red",
        minHeight:"100%"
    
    },
    container:{
        display:"flex",
        backgroundColor:'red',
        

    },
    check:{
        color:"red",
    }

 })

 export default HomeScreen;