//
//  NSUserDefaultsManager.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/25/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class NSUserDefaultsManager: NSObject {
    static let userDefaults = UserDefaults.standard
    
    class func sychronize() {
        let myData = NSKeyedArchiver.archivedData(withRootObject: Business.customers)
        UserDefaults.standard.set(myData, forKey: "customerarray")
        UserDefaults.standard.synchronize()
    }
    
    class func initializeDefaults() {
        if let customersRaw = UserDefaults.standard.data(forKey: "customerarray"){
            if let customers = NSKeyedUnarchiver.unarchiveObject(with: customersRaw) as? [Customer]{
                Business.customers  = customers
            }
        }
    }
}
